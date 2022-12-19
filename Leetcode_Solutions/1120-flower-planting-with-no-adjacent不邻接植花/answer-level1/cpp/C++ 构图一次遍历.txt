```
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> cols(N, 0);
        vector<vector<int> > g(N + 1);
        for (auto& p : paths) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for (int i = 1; i <= N; ++i) {
            set<int> s{1, 2, 3, 4};
            for (auto j : g[i]) {
                s.erase(cols[j - 1]);
            }
            cols[i - 1] = *s.begin();
        }
        return cols;
    }
};
```
![image.png](https://pic.leetcode-cn.com/69a9d201a13e5355d3ddbdbf7424cafdf8fa05ab3efb9b3f6121b116a3a4bd9f-image.png)
