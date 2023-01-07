#include <bits/stdc++.h>
using namespace std;

// Accepted
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> cows(10, 0);
        int bullsCount = 0;
        int cowsCount = 0;
        for (int i = 0; i < secret.size(); i++) {
            cows[secret[i]-'0']++;
        }
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == secret[i]) {
                cows[guess[i]-'0']--;
                bullsCount++;
            }
        }
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] != secret[i] and cows[guess[i]-'0'] > 0) {
                cows[guess[i]-'0']--;
                cowsCount++;
            }
        }
        return to_string(bullsCount)+'A'+to_string(cowsCount)+'B';
    }
};