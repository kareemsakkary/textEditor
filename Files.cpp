//
// Created by Kareemsakkary on 5/9/2022.
//
#include "Files.h"
string open(string fileName){
    fstream file;
    file.open(fileName,ios::in);
    if (file.fail()) {
        cout << "This is a new file. I created it for you " << endl;
    }else{
        cout << "This File Already Exists" << endl;
    }
    string data,line;
    while (getline(file, line)) {
        data += line+"\n";
    }
    file.close();
    return data;
}
string openIfExist(string fileName){
    fstream file;
    file.open(fileName,ios::in);
    if (file.fail()) {
        cout << "Invalid file name." << endl;
    }
    string data,line;
    while (getline(file, line,'\n')) {
        data += line+"\n";
    }
    file.close();
    return data;
}
void save(string data){
    string fileName;
    cout << "enter name for the new file : ";
    cin >> fileName;
    fstream file;
    file.open(fileName,ios::out);
    file << data;
    file.close();
}


void merge(string data){
    string fname,newData;
    cout << "Enter file name to merge : ";
    cin >> fname;
    newData = openIfExist(fname);
    data += " "+newData;
}

void countWords(string data){
    int count=0;
    for(char c :data){
        if(c == '\n'||c == '\t'||c == ' '){
            count++;
        }
    }
    cout << "number of words = "<<count<<endl;
}

void countChars(string data){
    cout << "number of characters = "<<data.size()<<endl;
}

void countLines(string data){
    int count=0;
    for(char c :data){
        if(c == '\n'){
            count++;
        }
    }
    cout << "number of lines = "<<count<<endl;
}

string upper(string s){
    string upper_s;
    for (char c : s){
        upper_s += toupper(c);
    }
    return upper_s;
}

void searchWord(string data){
    string word;
    cout << "Enter word to search : ";
    cin >> word;
    regex rg("("+upper(word)+")(.*)");
    if(regex_search(upper(data),rg)){
        cout << "Word was found in the file "<< endl;
    }else{
        cout << "Word was not found in the file " << endl;
    }
}
void countNumOfWord(string& data) {
    string word;
    cout << "Enter a word you want to count: ";
    cin >> word;
    string regexPattern = "\\b" + word + "\\b";
    const regex pattern(regexPattern);
    int count = 0;
    auto it = sregex_iterator(data.begin(), data.end(), pattern);
    for (it; it != sregex_iterator(); it++) {
        count++;
    }
        cout << "The word" << ' ' << word << ' ' << "was found" << ' ' << count << ' ' << "times" << endl;
}
void uppercase(string& data){
    for (int i = 0; i < data.size(); i++) {
        data[i] = toupper(data[i]);
    }
}
void lowercase(string& data){
    for (int i = 0; i < data.size(); i++) {
        data[i] = tolower(data[i]);
    }
}
void firstCaps(string& data) {

    int len = data.size();

    for (int i = 0; i < len; ++i) {
        if (i == 0) {
            if (islower(data[i]))
                data[i] = toupper(data[i]);
        } else {
            if (data[i] != ' ') {
                if (isupper(data[i]))
                    data[i] = tolower(data[i]);
            } else {
                i++;
                if (islower(data[i]))
                    data[i] = toupper(data[i]);
            }
        }
    }
}