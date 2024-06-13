#include <iostream>
#include <windows.h>
#include <cstdio>
#include <fstream>
using namespace std;
void compile(string cppfile) {
    ofstream compile("compiler.bat");
    compile << " echo WATCH FOR COMPILATION ERRORS HERE!" <<  endl;
    compile << "g++ " << cppfile << " -o " << cppfile << ".exe" << endl;
    compile.close();
    system("compiler.bat");
    remove("compiler.bat");
    return;
}
void save(string filename, string contents) {
    char tempPath[MAX_PATH];
    GetTempPathA(MAX_PATH, tempPath);
    string tempFilePath{tempPath};
    tempFilePath = tempFilePath + "lucastext\\" + filename;
    ofstream savedata(tempFilePath);
    savedata.close();
    cout << tempFilePath;
    cout << contents;
    cout << filename;

}
void write(string filename) {
    string input;
    ofstream writing(filename);
    std::cout << filename << " has been created! Type to add now!\nType #exit to exit!\nPro tip, use Ctrl + Shift + V to paste contents.";
    while (write) {
        getline(cin, input);

        if (input == "#exit") {
            break;
        }
        writing << input << endl;
    }
    cout << "File written successfully!\n";
    return;
}

void read(string filename) {
    ifstream read(filename);
    if (read) {
        cout << "Reading " << filename << endl;
    }
    if (!read) {
        cout << "Problem reading " << filename << endl;
        return;
    }
    while (!read.eof()) {
        string output;
        getline(read, output);
        if (!read.eof()) {
            cout << output << endl;
        }
        if (read.eof()) {
            cout << output;
        }
    }
}
