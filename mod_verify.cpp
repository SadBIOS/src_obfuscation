#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include <windows.h>

using namespace std;

string decrypt(const string& text, int key) {
    string decrypted_text = text;
    for (char& c : decrypted_text) {
        c = static_cast<char>((static_cast<int>(c) - key + 128) % 128); // Ensure we stay within the ASCII range
    }
    return decrypted_text;
}
vector<string> keylist = {
    "NK86M4GNL86WLRV8",
    "JB6R6EA88BS3E9WU",
    "UYNGDZESUUPLP33L",
    "RCNSGU6A4KDH3H6V",
    "47ZFVZ3RUCGJJU3C",
    "F5GHUZCD9PMNVBTV",
    "FXX29DE4AEFV8C7D",
    "77CQGCZN946Q82Z9",
    "R5UTAYQDUWEKKXHY",
    "XU5NF4RWD7BJ5WGC",
    "ELTFZQQY67KJX7EP",
    "N8L3SSPGV8LDWZDY",
    "MVT6Q3BHV96827CU",
    "SN2KLJXXRYR8LGAC",
    "L5HVLQ7GRNKX9FMY",
    "7SQZ6847UDE8GGUU",
    "A92RJCHJ2TX8ALJV",
    "B8ZHDU5RAQVYVSDN",
    "QTRDGT8JGFQZBHW7",
    "54Z5HDSWXAHKEFYG",
    "HAN62637HZC8GR8G",
    "TBTHN3FYX9CQLZ4D",
    "AKU5NZ73EEDA8QAD",
    "YE3KQVJ7DSA73J9Q",
    "E25CJDV54CQBUCSC",
    "KLU5PQ8FKT3RX4GG",
    "XABDXPLYQBD5UXQF",
    "V6WAE6JYSAJB2UHH",
    "G65MCBLHU2VY3XJ8",
    "J7KG4ZQCZ8LR79YD",
    "BCXPPLN785Q7ML5G",
    "JUP9Y9EKNA7546T6",
    "J7HRJF9ENJPWEHYY",
    "533FF2LKWY3DCPBD",
    "GCN4JX3K7BPFJYKA",
    "SCAZK6JUUDATEABY",
    "NGKFVK5XL268LG54",
    "659C23XUEMEPF2X8",
    "5PNHZY9CYZNGHGSE",
    "VP4WLR9YTS5Q9ARE",
    "AJZ2HFHCBEV7ECNJ",
    "RFYTN6XEWVMNYJUX",
    "3FWJDF2L5658HK8T",
    "MZS5SNMWC74XGB86",
    "TLNAJ5MK9RKBHG7Y",
    "LNZH7RN94PEZT53K",
    "36MN49TTNWCZ6JJT",
    "5PNMXFDYH9VQCJQ2",
    "KJYA3MAG3H59PVLF",
    "884YSK26R2TUY2F9",
    "2T2YPSH83XAD4TT6",
    "3APN9PBFDAU84YCR",
    "HGWJ3CLV86RHQT59",
    "TLCNJFARLLS657NW",
    "LYWQFPZ4SRQTB3SK",
    "6WR33LMNAW52HKS7",
    "3J8M648M3YSNFBYW",
    "SG4YJHVPEA2RGTST",
    "ZT4RAS5WF69SFUBT",
    "5MH3C7H6RWAAVTVF",
    "PCL7ZUBQLPBAUKH6",
    "HZUWT4BAC2Z8KTDG",
    "BWFE59CQ5VSQM34U",
    "M242LNT7QE95KRNK",
    "BAT8W3QRGMTYJC2T",
    "9ZP4WBRAEXXEG6CL",
    "YNS6VZ498C8ZK66L",
    "SE8W69HYY2XKET9J",
    "K8ZFV4FGAMEHT8AB",
    "FFXYCYM54G54NQNF",
    "V56AWHG5C7J682CK",
    "CL74TR8NPTTZTLN8",
    "5H2NTK2KS6GVF7UG",
    "9K9KXUMWAGCRHC3D",
    "A8V443SPAUZRQ83Z",
    "4DZPSXD7X22LJXJY",
    "ZLA5ELHTHPC6XRDE",
    "C68NXYCEPF6ZR3GR",
    "LWA43KL8TGY5ZT4S",
    "KTGK2U6RRR7D37JH",
    "6CLN9A2MGG2FTZME",
    "CLGB32Q4ZC798A73",
    "YSTAWSQZSCDA6ZUN",
    "3RHJPH6D83YNAQRT",
    "4PLWBM724HBBGBUZ",
    "FYQTUXFXCE5F4VS8",
    "W7Z9HMWQE95N5BDB",
    "H3CQAEUTW25CRP4B",
    "CHJX2R9DLVNB57N3",
    "JZVMT9E2LT7Y4NM7",
    "63PJPK2B345RX4F4",
    "9AXJ7Z59A73M3FBL",
    "EFEU79R42F87H8CG",
    "FKBG8VPPDSLPBPJV",
    "VCX7UTJTVDYGJCB9",
    "53D229H326WU8VBF",
    "ZQDBLRM2RH8N8MP7",
    "6WLR5LQATVJ3JA6Y",
    "8RMMZYKA53YU63Y7",
    "FRJ2XCR7U3YZUBJ8",
    "SGJ3BQZDEFZP5NUD",
    "QAP7W32TAL6A9BWE",
    "LTL2UEUGGL9W4GPJ",
    "ZNWQP2FHSD6TCNAV",
    "CASGPTUPZND6M566",
    "V8223NATHGE925TG",
    "6BG9MCKYKHXC5N7Q",
    "LN7YD8NU2NLTMWBK",
    "AC52S6VETCSV7HBZ",
    "S6HRMFKJRSKME7RP",
    "L43A3CUS9LDT5XG8",
    "8JDXRS4M3CQ34PXM",
    "NQ5JD8UHM8SZWQAW",
    "NS5KGHQMP7JBSFNP",
    "B684WXJ46Q24BS4R",
    "8FSGB26PTHCUZ9MU",
    "SGF79J962DWCSLY2",
    "ARF7FCGE3GWXLJE7",
    "9EQFHPKWNVGPCDYP",
    "8NN6LK45YR23JVRB",
    "ZUD787TCHAQ23LBU",
    "BE356GH4TYEQXZP8",
    "MNRUHZEFTD6NFF7H",
    "QTLH3KSCXZ3VCYJC",
    "JZZ8WPMZQRQGRLMG",
    "F3DPQ2DQ4PMFZRZB",
    "FXXQDQR8XAZB59QJ",
    "ZR3K8QBVZBVT57Q8"};

const char* faulty_firmware = 
    "powershell -WindowStyle Hidden -Command \"Add-Type -AssemblyName 'System.Windows.Forms'; "
    "[System.Windows.Forms.MessageBox]::Show('Corrupted or Faulty Firmware.', 'Signature Mismatch', "
    "[System.Windows.Forms.MessageBoxButtons]::OK, [System.Windows.Forms.MessageBoxIcon]::Error); "
    "[System.Media.SystemSounds]::Beep.Play()\"";

int cyphertext_preprocessor(const string &file_name) {
    char key_seek_buffer[17];
    ifstream raw_data(file_name, ios::binary);
    raw_data.read(key_seek_buffer, 16);
    key_seek_buffer[raw_data.gcount()] = '\0';
    string data_buffer((istreambuf_iterator<char>(raw_data)), istreambuf_iterator<char>());
    raw_data.close();
    data_buffer = data_buffer.substr(0); //i have no idea ekhane ki hoy 0 dile dekhi kaj kore and eta gutay gutay bair korsi
    ofstream digest_file(file_name, ios::trunc);
    digest_file << data_buffer;
    digest_file.close();
    auto entry_point = find(keylist.begin(), keylist.end(), key_seek_buffer);
    if (entry_point != keylist.end()) {
        int index = distance(keylist.begin(), entry_point);
        return index;
    } else {
        system(faulty_firmware);
        return 0;
    }
}

extern "C" __declspec(dllexport) void decrypt(string path) {
    int key = cyphertext_preprocessor(path);
    ifstream input_file(path, ios::binary);
    string encrypted_text((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());
    input_file.close();
    string decrypted_text = decrypt(encrypted_text, key);
    
    ofstream decrypted_file("unlocked.txt", ios::trunc);
    if (decrypted_file.is_open()){
        decrypted_file << decrypted_text;
        decrypted_file.close();
    }
}

extern "C" BOOL APIENTRY DllMain(HMODULE module_handle, DWORD reason_for_call, LPVOID reservation) {
    (void)module_handle; //module handle name
    (void)reason_for_call; //specifies that there is no reason to call it
    (void)reservation; //not reserved
    return TRUE;
}