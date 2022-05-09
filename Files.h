//
// Created by Kareemsakkary on 5/9/2022.
//

#ifndef TEXTEDITOR_FILES_H
#define TEXTEDITOR_FILES_H
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>

using namespace std;

string open(string fileName){
    fstream file;
    file.open(fileName,ios::in);
    if (file.fail()) {
        cout << "This is a new file. I created it for you " << endl;
    }else{
        cout << "This File Already Exists" << endl;
    }
    string data;
    file >> data;
    file.close();
    return data;
}
void save(string fileName,string data){
    fstream file;
    file.open(fileName,ios::out);
    file << data;
    file.close();
}

#endif //TEXTEDITOR_FILES_H
