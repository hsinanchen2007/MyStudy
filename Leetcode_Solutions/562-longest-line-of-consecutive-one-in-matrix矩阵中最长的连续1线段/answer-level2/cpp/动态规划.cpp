### 解题思路

### 代码

```cpp
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.size()==0) return 0;
        int _M[M.size()][M[0].size()][4];
        int re = 0;
        for (int i=0; i<M.size(); i++) {
            for (int j=0; j<M[0].size(); j++) {
                if (M[i][j]==1) {
                    _M[i][j][0] = j==0 ? 1 : _M[i][j-1][0]+1;
                    _M[i][j][1] = i==0 ? 1 : _M[i-1][j][1]+1;
                    _M[i][j][2] = i==0||j==0 ? 1 : _M[i-1][j-1][2]+1;
                    _M[i][j][3] = i==0||j==M[0].size()-1 ? 1 : _M[i-1][j+1][3]+1;
                    for (int k=0; k<4; k++) {
                        re = max(re, _M[i][j][k]);
                    }
                }
                else {
                    for (int k=0; k<4; k++) {
                        _M[i][j][k] = 0;
                    }
                }
            }
        }
        return re;
    }
};
```