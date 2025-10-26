#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

string rawWord(string w) {

    string result = "";

    for (char c: w) {

        if ( isalpha (c) ) {
            result += tolower(c);
        }

    }

    return result;
}


int main() {

    ifstream book("fulltext.txt");

    if(!book.is_open()) {

        cout << "Error opening file." << endl;

        return 1;
    }

    vector<string> words;

    string word;

    while (book >> word) {

        words.push_back( rawWord(word) );

    }

    book.close();

    cout << "Book title: Crime and Punishment" << endl;

    int countOfLove = 0;

    for (string w: words) {

        if (w == "love") {

            countOfLove++;

        }

    }

    cout << "The word 'love' appears " << countOfLove << " times in the book." << endl;

    ifstream again("fulltext.txt");

    string a = "";

    char b;

    while(again.get(b)) {

        a += b;


    }

    again.close();

    int setenceCount = 0;

    string currentSentence = "";

    string longestSentence = "";

    for (char c: a) {

        currentSentence += c;

        if (c == '.' || c == '!' || c == '?') {

            setenceCount++;

            if (currentSentence.length() > longestSentence.length()) {

                longestSentence = currentSentence;

            }

            currentSentence = "";

        }

    }

    cout << "The book contains " << setenceCount << " sentences." << endl;

    cout << "The longest sentence is: " << longestSentence << endl;


    // string highestWord = "";

    // int highestCount = 0;

    // for (int i = 0; i < words.size(); i++) {

    //     string currentWord = words[i];

    //     int currentCount = 0;

    //     for (int j = 0; j < words.size(); j++) {

    //         if (words[j] == currentWord) {

    //             currentCount++;

    //         }

    //     }

    //     if (currentCount > highestCount) {

    //         highestCount = currentCount;

    //         highestWord = currentWord;

    //     }

    // }

    // cout << "The most frequent word is '" << highestWord << "' which appears " << highestCount << " times." << endl;

    


    cout << "Review complete." << endl;


    return 0;
}