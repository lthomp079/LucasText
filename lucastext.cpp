#include "lucastext.h"
using namespace std;
int main(int argc, char* argv[]) {
    bool args = true;
    if (argc != 1) {
    if (string(argv[1]) == "read") {
        string stringargv = argv[2]; 
        read(stringargv);    
        args = false;
    }
        if (string(argv[1]) == "write") {
            string stringargv = argv[2];
            write(stringargv);
            args = false;
        }
        if (string(argv[1]) == "comp" || string(argv[1]) == "compile") {
            string stringargv = argv[2];
            compile(stringargv);
            args = false;
        }
    }
    if (args == true) {
    char choice;
    string filename;
    cout << "Read, Write, or Compile? (type r, w or c)";
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 'R':
        case 'r':
        cout << "File to read:\n";
        cin >> filename;
        read(filename);
        break;
        case 'W':
        case 'w':
        cout << "What file are you creating?\n";
        getline(cin, filename);
        write(filename);
        break;
        case 'C':
        case 'c':
        cout << "What is the name of the file you want to compile? (Remember the .cpp extension!!!)" << endl;
        getline(cin, filename);
        compile(filename);
        cout << "Compiled succesfully!" << endl;
        break;      
        default:
        cout << "Choice not understood.\n";
        break;

    }
    }
    cout << endl;
    system("PAUSE");
}