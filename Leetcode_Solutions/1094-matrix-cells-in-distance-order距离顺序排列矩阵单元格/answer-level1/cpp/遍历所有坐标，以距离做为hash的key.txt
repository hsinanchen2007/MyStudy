### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        map<int, vector<vector<int>>> m;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                int d = abs(r - r0) + abs(c - c0);
                m[d].push_back({r, c});
            }
        }
        vector<vector<int>> res;
        for (auto& p : m) {
            for (int i = 0; i < p.second.size(); ++i) {
                res.push_back(p.second[i]);
            }
        }
        return res;
    }
};
```