#include <bits/stdc++.h>
using namespace std;

// Accepted

class Solution {
public:
    void recurse(int n, int k, vector<vector<int>> &sln, vector<int> &ans, int i = 1) {
        if (k == 0 and n == 0) {
            sln.push_back(ans);
            return ;
        }
        if (i > 9) return;
        if (i > n) return;
        recurse(n, k, sln, ans,  i+1);
        if (n - i < 0) return;
        ans.push_back(i);
        recurse(n-i, k-1, sln, ans, i+1);
        ans.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> sln;
        vector<int> ans;
        recurse(n, k, sln, ans);
        return sln;
    }
};