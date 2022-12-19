### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        if (land.empty() || land[0].empty()) {
            return vector<int>();
        }
        
        vector<int> res;
        int direcs[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[0].size(); ++j) {
                if (land[i][j] != 0 || land[i][j] == -1) {
                    continue;
                }
                int ret = backtrace(land, direcs, i, j);
                res.push_back(ret);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    int backtrace(vector<vector<int>>& land, int direcs[8][2], int x, int y) {
        if (x < 0 || x >= land.size() || y < 0 || y >= land[0].size()) {
            return 0;
        }
        if (land[x][y] != 0 || land[x][y] == -1) {
            return 0;
        }
        int cnt = 1;
        land[x][y] = -1;
        for (int i = 0; i < 8; ++i) {
            cnt += backtrace(land, direcs, x + direcs[i][0], y + direcs[i][1]);
        }
        return cnt;
    }

};
```