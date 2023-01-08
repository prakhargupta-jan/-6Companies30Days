#include <bits/stdc++.h>
using namespace std;

// Accepted

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<vector<int>> pp(nums.size());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if (nums[i]%nums[j] == 0 and pp[i].size() < pp[j].size()) {
                    pp[i] = pp[j];
                }
            }
            pp[i].push_back(nums[i]);
        }
        int mxIndex = -1, mxSize = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pp[i].size() > mxSize) {
                mxSize = pp[i].size();
                mxIndex = i;
            }
        }
        return pp[mxIndex];
    }
};