#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

/*
 * Input:
 * 5
 * ABC
 * ACB
 * BAC
 * CAB
 * CBA
 *
 * OUTPUT:
 * BCA
 */


using namespace std;

int findWho(vector<string> inputString, int pos, int charNum){
    vector<int> countNum(11);
    countNum.resize(charNum);

    for(int i=0; i<inputString.size(); i++){
        string st = inputString[i];   // get input string i
        countNum[st[pos]-'A'] ++;      // get the char[pos] of string i
    }

    // return the least number's id
    vector<int>::iterator last;
    std::vector<int>::iterator smallest = std::min_element(countNum.begin(), countNum.end());

    int id = std::distance(countNum.begin(), smallest);

    return id;

}


int main(){
    int n = 0;
    cin >> n;  // n lines
    string temp;
    vector<string> inputString;


    for(int i=0; i<n; i++){
        cin >> temp;
        inputString.push_back(temp);

    }

    // --------------------

    int charNum = inputString[0].size();

    for (int i=0; i < charNum; i++){
        cout << char('A'+findWho(inputString, i, charNum));
    }

    return 0;
}

