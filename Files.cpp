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
    while (getline(file, line,'\n')) {
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
void save(string fileName,string data){
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