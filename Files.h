//
// Created by Kareemsakkary on 5/9/2022.
//

#ifndef TEXTEDITOR_FILES_H
#define TEXTEDITOR_FILES_H
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>

using namespace std;

string open(string fileName);

string openIfExist(string fileName);

void save(string data);


void merge(string data);
void countWords(string data);
void countChars(string data);
void countLines(string data);
void searchWord(string data);
#endif //TEXTEDITOR_FILES_H
void countNumOfWord(string& data);
void uppercase(string& data);
void lowercase(string& data);
void firstCaps(string& data);
void addContent(string& data);