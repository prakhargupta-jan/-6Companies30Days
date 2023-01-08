#include <bits/stdc++.h>
using namespace std;

// Accepted

class Solution {
public:
    bool dfs(int &numCourses, int &x, unordered_map<int, vector<int>> &links, vector<bool>& visited, vector<bool>& globalVisited) {
        bool check = false;
        if (visited[x])
            return true;
        if (globalVisited[x])
            return false;
        globalVisited[x] = true;
        visited[x] = true;
        for (auto y : links[x]) {
            check = check | dfs(numCourses, y, links, visited, globalVisited);
        }
        visited[x] = false;
        return check;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> links;
        vector<bool> globalVisited(numCourses, 0);
        for (auto x : prerequisites) {
            links[x[1]].push_back(x[0]);
        }
        for (int i = 0;i < numCourses; i++) {
            vector<bool> visited(numCourses,0);
            bool check = dfs(numCourses, i, links, visited, globalVisited);
            if (check)
                return false;
        }
        return true;
    }
};