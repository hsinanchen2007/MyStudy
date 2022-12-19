### 解题思路
dfs

### 代码

```cpp
class Solution {
public:
    int ans = 0;
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> matrix(3, vector<int>(3,0));
        //vector<vector<int> > directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                GetCount(matrix, i, j, 0, m, n);
            }
        }
        return ans;
    }

    void GetCount(vector<vector<int>>& matrix, int x, int y, int step, int m, int n) {
        step = step + 1;
        matrix[x][y] = 1;
        if (step >= m && step <= n) {
            ++ans;
        }
        if (step == n) {
            matrix[x][y] = 0;
            return;
        }

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if (i == x && j == y) {
                    continue;
                }
                if (matrix[i][j] == 1) {
                    continue;
                }
                if (abs(x-i)%2==0 && abs(y-j)%2==0 && matrix[(x+i)/2][(y+j)/2] == 0) {
                        continue;
                }
                GetCount(matrix, i, j, step, m, n);
            }
        }
        matrix[x][y] = 0;
    }
};
```