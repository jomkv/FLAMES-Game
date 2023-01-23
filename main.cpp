
#include "functions.hpp"

int main() {
    string name1, name2;
    gettingInput:
    getInput(name1, name2);
    
    string origLetters = getAllOrigLetters(name1, name2);
    
    if(origLetters.empty()) {
        cout << endl << "Both names cannot be the same. Try again" << endl << endl; 
        goto gettingInput;
    }
    
    int flamesIndex = keepInRange(origLetters.size());

    string flames[] = {"Friendship", "Love", "Affection", "Marriage", "Enemy", "Soulmate"};
    cout << endl << "Relationship: " << flames[flamesIndex-1] << endl;

    return 0;
}

