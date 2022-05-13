#include <iostream>
#include "Files.h"
#include <regex>
using namespace std;

string filename, data;

int menu();

int main() {
    cout << "Enter file name : ";
    cin >> filename;
    data = open(filename);
    bool run = true;
    while (run){
        int op = menu();
        switch (op) {
            case 1:
                addContent(data);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                merge(data);
                break;
            case 7:
                countWords(data);
                break;
            case 8:
                countChars(data);
                break;
            case 9:
                countLines(data);
                break;
            case 10:
                searchWord(data);
                break;
            case 11:
                countNumOfWord(data);
                break;
            case 12:
                uppercase(data);
                break;
            case 13:
                lowercase(data);
                break;
            case 14:
                firstCaps(data);
                break;
            case 15:
                save(data);
                break;
            case 16:
                run = false;
                break;
        }
    }
    return 0;
}

int menu(){
    int op;
    cout << "Choose what you need to do \n";
    cout << "1. Add new text to the end of the file \n"
            "2. Display the content of the file\n"
            "3. Empty the file\n"
            "4. Encrypt the file content \n"
            "5. Decrypt the file content\n"
            "6. Merge another file\n"
            "7. Count the number of words in the file.\n"
            "8. Count the number of characters in the file\n"
            "9. Count the number of lines in the file\n"
            "10. Search for a word in the file\n"
            "11. Count the number of times a word exists in the file\n"
            "12. Turn the file content to upper case.\n"
            "13. Turn the file content to lower case.\n"
            "14. Turn file content to 1st caps (1st char of each word is capital) \n"
            "15. Save\n"
            "16. Exit\n"
            "--> ";
    cin >> op;
    return op;
}


