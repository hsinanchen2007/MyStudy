### 解题思路
预处理行前缀和，列前缀和。在枚举方阵的起点坐标(i,j)和方阵边长len。需要满足以下四个条件(题意要求 4 条边皆为黑色像素)：
1. row[r][c+i] - row[r][c] + mat[r][c] == 0
2. row[r+i][c+i] - row[r+i][c] + mat[r+i][c] == 0
3. col[r+i][c] - col[r][c] + mat[r][c] == 0
4. col[r+i][c+i] - col[r][c+i] + mat[r][c+i] == 0

满足条件，即可更新答案为当前坐标和边长。

### 代码

```cpp
class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = -1;
        vector<vector<int>> row(n, vector<int>(m, 0));
        vector<vector<int>> col(n, vector<int>(m, 0));
        vector<int> ret;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                row[i][j] = j == 0 ? mat[i][j] : row[i][j-1] + mat[i][j];
            }
        }

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                col[j][i] = j == 0 ? mat[j][i] : col[j-1][i] + mat[j][i];
            }
        }

        for(int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                for(int i = ans + 1; i + r < n && i + c < m; ++i) {
                    if(row[r][c+i] - row[r][c] + mat[r][c] != 0) continue;
                    if(row[r+i][c+i] - row[r+i][c] + mat[r+i][c] != 0) continue;
                    if(col[r+i][c] - col[r][c] + mat[r][c] != 0) continue;
                    if(col[r+i][c+i] - col[r][c+i] + mat[r][c+i] != 0) continue;
                    ans = i;
                    ret = {r, c, i + 1};
                }
            }
        }

        return ret;
    }
};
```