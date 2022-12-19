### 解题思路
由于每行中1均在0之前，故按列检测，遇到为0的行时，保存该行号，同时对已记录过的行做记录

### 代码

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        if (mat.empty() || mat[0].empty() || k <= 0) {
            return {};
        }
        vector<int> res;
        vector<int> visited(mat.size(), 0);
        for (int c = 0; c < mat[0].size(); ++c) {
            for (int r = 0; r < mat.size(); ++r) {
                if (mat[r][c] == 0 && visited[r] == 0) {
                    res.push_back(r);
                    visited[r] = 1;
                    if (res.size() == k) {
                        return res;
                    }
                }
            }
        }
        // 出现整行为1的情况
        for (int i = 0; i < visited.size(); ++i) {
            if (res.size() == k) break;
            if (visited[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
```