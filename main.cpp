#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

extern "C" __declspec(dllimport) void encrypt(string path);
extern "C" __declspec(dllimport) void decrypt(string path);

int main(int argc, char* argv[]) {

    HMODULE tala = LoadLibrary("mod_sign.dll");
    HMODULE chabi = LoadLibrary("mod_verify.dll");

    if (argc != 3) {
        cout << "binary.exe -enc [filepath] or -dec [filepath]" << endl;
        return 1;
    }

    string action = argv[1];
    string file_path = argv[2];


    if (action == "-enc") {
        encrypt(file_path);
    } else if (action == "-dec") {
        decrypt(file_path);
    } else {
        cout << "Invalid argument. Use -enc or -dec." << endl;
        return 1;
    }
    
    FreeLibrary(tala);
    FreeLibrary(chabi);
    return 0;
}