#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <sstream>
using namespace std;

unordered_map<string, int> M = {
    {"nol", 0}, 
    {"satu", 1}, 
    {"dua", 2}, 
    {"tiga", 3}, 
    {"empat", 4},
    {"lima", 5}, 
    {"enam", 6}, 
    {"tujuh", 7}, 
    {"delapan", 8}, 
    {"sembilan", 9},
    {"sepuluh", 10}, 
    {"sebelas", 11}
};

long long parseThreeDigits(const vector<string>& words) {
    long long result = 0, temp = 0;
    for (string word : words) {
        if (word == "ratus") {
            temp *= 100;
            result += temp;
            temp = 0;
        } else if (word == "puluh") {
            temp *= 10;
            result += temp;
            temp = 0;
        } else if (word == "belas") {
            temp += 10;
            result += temp;
            return result;
        } else if (word == "seratus") {
            result += 100;
        } else {
            temp += M[word];
        }
    }

    result += temp;
    return result;
}

long long textToDigits(const string& text) {
    stringstream ss(text);
    string word;
    vector<string> segmentWords;
    long long result = 0LL;

    while(ss >> word) {
        if (word == "triliun") {
            result += parseThreeDigits(segmentWords) * 1'000'000'000'000;
            segmentWords.clear();
        } else if (word == "miliar") {
            result += parseThreeDigits(segmentWords) * 1'000'000'000;
            segmentWords.clear();
        } else if (word == "juta") {
            result += parseThreeDigits(segmentWords) * 1'000'000;
            segmentWords.clear();
        } else if  (word == "ribu") {
            result += parseThreeDigits(segmentWords) * 1'000;
            segmentWords.clear();
        } else if (word == "seribu") {
            result += 1'000;
        } else {
            segmentWords.push_back(word);
        }
    }

    result += parseThreeDigits(segmentWords);
    return result;
}

int main() {
    string text = "dua ratus tujuh puluh satu triliun dua ratus tujuh puluh satu miliar dua ratus tujuh puluh satu juta dua ratus tujuh puluh satu ribu dua ratus tujuh puluh satu";
    cout << textToDigits(text);
}
