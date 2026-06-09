### 解题思路
模拟四个方向，遍历整个数组 {{0,1},{1,0},{1,1},{-1,1}};

### 代码

```cpp
class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{1,1},{-1,1}};
    bool IsValid(vector<vector<int>>& M, int x, int y) 
    {
        if (x < 0 || x >= M.size() || y < 0 || y >=M[0].size()) {
            return false;
        }
        if (M[x][y] == 1) {
            return true;
        } else {
            return false;
        }
    }
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[i].size(); j++) {
                if (M[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int tempAns = 1;
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        while(IsValid(M, x, y)) {
                            x += dir[k][0];
                            y += dir[k][1];
                            tempAns++;
                        }
                        ans = max(tempAns, ans);
                    }
                }
            }
        }
        return ans;
    }
};
```