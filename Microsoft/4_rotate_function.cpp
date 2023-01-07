#include <bits/stdc++.h>
using namespace std;

// Accepted

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int tsm = 0, test = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            test+=i*nums[i];
            tsm+=nums[i];
        }
        int sln = test;
        for (int i = 0; i < n-1; i++) {
            test-=tsm-nums[i];
            test+=nums[i]*(n-1);
            sln = max(sln, test);
        }
        return sln;
    }
};