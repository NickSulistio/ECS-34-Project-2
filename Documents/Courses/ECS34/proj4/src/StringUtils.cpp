#include "StringUtils.h"
#include <algorithm> 
#include <cctype>
#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

namespace StringUtils{
    
std::string Slice(const std::string &str, ssize_t start, ssize_t end){
    // Your code goes here
    std::string newString;
    if (end < 0) {
        end = end + str.length();
    }
    if(end==0) {
        end = str.length();
    }
    if (end > (str.length() -1) or start > (str.length()-1)){
        return "";
    }
    int counter = start;
    if (start <0) {
        start = start + str.length();
    }

    for(int x = 0; x <str.length(); x++) {
        if (counter < end) {
            newString +=str[counter];
            counter++;
        }
    }
    return newString;
}

std::string Capitalize(const std::string &str){
    // Your code goes here
    std:: string newString = str;
    std::transform(newString.begin(), newString.end(), newString.begin(), ::tolower);
    newString[0] = toupper(newString[0]);
    return newString;
}


std::string Title(const std::string &str){
    // Your code goes here
    std::string newString = str;
    bool thisWordCapped = false;
    //Turn all letters lowercase
    std::transform(newString.begin(), newString.end(), newString.begin(), ::tolower);

    for (unsigned int i=0; i<newString.length();i++) {
        //At a space or punctuation mark, the current word has ended.
        //We are now on a new word that has not yet been capitalized,
        //so thisWordCapped is set to false.
        if ((ispunct(newString[i])) || (isspace(newString[i])) || (isdigit(newString[i])))
        thisWordCapped = false;

        //If current word has not been capitalized AND the current character
        //is a letter, uppercase the letter. The word is now capitalized, so
        //thisWordCapped is set to true, and will not be set to false until
        //a space or punctuation is found.
        if ((thisWordCapped==false) && (isalpha(newString[i])))
        {
            newString[i]=toupper(newString[i]);
            thisWordCapped = true;
        }
    
    }
    return newString;

}
// http://vertstudios.com/blog/c-capitalize-word-proper-case/

std::string LStrip(const std::string &str){
    // Your code goes here
    std::string newString = str;
    newString = newString.substr(newString.find_first_not_of(" \n\r\t"));
    return newString;
}

std::string RStrip(const std::string &str){
    // Your code goes here
    std::string newString = str;    
    newString.erase(newString.find_last_not_of(" \n\r\t")+1);
    return newString;
}

std::string Strip(const std::string &str){
    // Your code goes here
    std::string newString = str;
    newString = newString.substr(newString.find_first_not_of(" \n\r\t"));
    newString.erase(newString.find_last_not_of(" \n\r\t")+1);
    return newString;
}

std::string Center(const std::string &str, int width, char fill){
    // Your code goes here
    std::string newString = str;
    int strLen = newString.length();
    if (width < strLen) {
        return newString;
    }
    else { 
        int adjustBy = width-strLen;
        int centerBy = adjustBy/2;
        newString.insert(newString.begin(),centerBy,fill);
        if (adjustBy % 2 !=0) {
            centerBy +=1;
        }
        newString.append(centerBy, fill);
        
    }
    return newString;
}

std::string LJust(const std::string &str, int width, char fill){
    // Your code goes here
    std::string newString = str;
    int strLen = newString.length();
    if (width < strLen) {
        return newString;
    }
    else { 
        int adjustBy = width-strLen;
        newString.append(adjustBy, fill);
    }
    return newString;
}

std::string RJust(const std::string &str, int width, char fill){
    // Your code goes here
    std::string newString = str;
    int strLen = newString.length();
    if (width < strLen) {
        return newString;
    }
    else { 
        int adjustBy = width-strLen;
        newString.insert(newString.begin(),adjustBy,fill);
    }
    return newString;
}
std::string Replace(const std::string &str, const std::string &old, const std::string &rep){
    // Your code goes here
    std::string newString = str;
    size_t start_pos = 0;
    while((start_pos = str.find(old, start_pos)) != std::string::npos) {
        newString.replace(start_pos, old.length(), rep);
        start_pos += rep.length(); // In case 'to' contains 'old', like replacing 'x' with 'yx'
    }
    return newString;
}
//https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string

std::vector<std::string> Split(const std::string &str, const std::string &splt){
    // Your code goes here
    std::vector<std::string> splittedString;
     int startIndex = 0;
     int  endIndex = 0;
     while( (endIndex = str.find(splt, startIndex)) < str.size() )
    {
       std::string val = str.substr(startIndex, endIndex - startIndex);
       splittedString.push_back(val);
       startIndex = endIndex + splt.size();
     }
     if(startIndex < str.size())
     {
       std::string val = str.substr(startIndex);
       splittedString.push_back(val);
     }
     return splittedString;
} 
//https://thispointer.com/how-to-split-a-string-in-c/

std::string Join(const std::string &str, const std::vector< std::string > &vect){
    // Your code goes here
    std::string newString;
    std::string tempString;
    for(int x=0;x<vect.size();x++){
        tempString = vect[x]+str;
        newString = newString+tempString;
    }
    return newString;
}
std::string ExpandTabs(const std::string &str, int tabsize){
    // Your code goes here
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase){
    // Your code goes here
}
}
