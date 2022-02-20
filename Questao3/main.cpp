#include <bits/stdc++.h>
using namespace std;

#define char_max 52

int toNum(char c){
    return (c - 'a');
}

int totanag(string str) {
    int n = str.length();

    map<vector<int>, int> mp;

    for (int i = 0; i < n; i++) {
        vector<int> freq(char_max, 0);

        for (int j = i; j < n; j++){
            freq[toNum(str[j])]++;
            mp[freq]++;
        }
    }

    int result = 0;
    for (auto it=mp.begin(); it!=mp.end(); it++)
    {
        int freq = it->second;
        result += ((freq) * (freq-1))/2;
    }
    return result;
}


int main()
{
    string str;
    cout << "Digite uma string qualquer: ";
    cin >> str;
    cout << totanag(str) << endl;
    return 0;
}
