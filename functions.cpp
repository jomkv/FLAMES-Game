#include "functions.hpp"

bool detectError(string name) {
    bool output = false;
    
    if (name.empty()) { // check if empty
        output = true;
    }
    else if (any_of(name.begin(), name.end(), ::isdigit)) { // check for digits on name1
        output = true;
    }
    else if (all_of(name.begin(),name.end(), ::isspace) || all_of(name.begin(),name.end(), [](char l){ // check if ALL the input is dot or space only
        if(l == '.') { return true; }
        else { return false; }
    })) { output = true; }
    else if (any_of(name.begin(), name.end(), [](char l){ // check if it contains non alphabetic chars
        if(l == ' ' || l == '.') { return false; }        // excludes space and dot 
        return !isalpha(l);
    })) { output = true; }
    
    return output;
}

void getInput(string& n1, string& n2) {
    getName1:
    cout << "Your name: ";
    getline(cin, n1);
    if(detectError(n1)) {
        cout << endl << "Your name is invalid. Try again" << endl << endl; 
        goto getName1; 
    } 
    getName2:
    cout << "Your crush's name: ";
    getline(cin, n2);
    if(detectError(n2)) {
        cout << endl << "Your crush's name is invalid. Try again" << endl << endl; 
        goto getName2; 
    } 
}

string findOrigLetters(string x, string y) {
    string output = "";
    int xLen = x.size(); 
    int yLen = y.size(); 
    for (int i = 0; i < xLen; i++) {
        char l1 = x[i];
        if (l1 == '.' || l1 == ' ') { continue; }
        bool isOrig = true;
        for (int j = 0; j < yLen; j++) {
            char l2 = y[j];
            if (tolower(l1) == tolower(l2)) {
                isOrig = false;
                break;  
            }
        }
        if (isOrig) { output += l1; }
    }
    return output;
}

string getAllOrigLetters(string n1, string n2) {
    string output = "";
    output += findOrigLetters(n1, n2);
    output += findOrigLetters(n2, n1);
    return output;
}

int keepInRange(int num) {
    int output = num;
    while ((output - 6) > 0) { output -= 6; }
    return output;
}   