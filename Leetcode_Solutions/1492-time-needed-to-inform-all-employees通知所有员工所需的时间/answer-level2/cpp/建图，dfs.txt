```cpp
class Solution {
public:
    static const int N = 100010;
    vector<int> G[N];
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                G[manager[i]].push_back(i);
            }
        }
        return f(n, headID, manager, informTime);
    }
    
    int f(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if (!informTime[headID]) return 0;
        int maxx = 0;
        for (int i = 0, sz = G[headID].size(); i < sz; ++i) {
            maxx = max(maxx, f(n, G[headID][i], manager, informTime));
        }
        return maxx+informTime[headID];
    }
};
```
