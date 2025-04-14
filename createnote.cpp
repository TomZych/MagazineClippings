#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool canCreateNote(const string& note, const vector<string> articles){
    unordered_map<char,int> charCount;

    for (const string& article : articles){
        for (char c : article){
            if (!isspace(c)){
                charCount[tolower(c)]++;
            }
        }
    }

    for (char c : note){
        if (!isspace(c)){
            if (charCount[tolower(c)] == 0){
                return false;
            }
            charCount[tolower(c)]--;
        }
    }
    return true;
}
int main(){
    string note;
    vector<string> articles;
    string article;
    
    cout << "Enter your note: " << "\n";
    getline(cin, note);

    cout << "Enter articles and say 'done' to stop: " << "\n";
    while (true){
        cout << " ";
        getline(cin, article);
        if (article == "done"){
            break;
        }
        articles.push_back(article);

    }

    if (canCreateNote(note, articles)){
        cout << "Results: true" <<endl;
    } else{
        cout << "Results: false" <<endl;
    }
    return 0;
}