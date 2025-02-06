main = main
icon_resource = enc_ico.rc
icon_obj = enc_ico.o
output = src_enc_tool.exe
enc_tool = mod_sign
dec_tool = mod_verify


default:
	windres -v $(icon_resource) -o coff -o $(icon_obj)
	g++ -shared -O3 -v -Wpedantic -Wall -Wextra -Wwrite-strings --extra-warnings -g3 -o $(enc_tool).dll $(enc_tool).cpp
	g++ -shared -O3 -v -Wpedantic -Wall -Wextra -Wwrite-strings --extra-warnings -g3 -o $(dec_tool).dll $(dec_tool).cpp
	g++ -L . -l $(enc_tool) -l $(dec_tool)  -O3 -v -Wpedantic -Wall -Wextra -Wwrite-strings --extra-warnings -g3 -o $(output) $(main).cpp $(icon_obj) -l gdi32

clean:
	powershell -Command "Remove-Item *.dll, *.exe, *.o  -Force -Verbose"