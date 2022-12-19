### 解题思路
深搜，到一个地方就判断是否满足题意，如果满足就总数加一。

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        dfs(m, n, k, 0, 0, vis);
        return count;
    }
private:
    int count = 0;
    int move_x[4] = {1, -1, 0, 0};
    int move_y[4] = {0, 0, 1, -1};
    inline int computeBit(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    void dfs(int m, int n, int k, int i, int j, vector<vector<int>>& vis) {
        if (vis[i][j] == 0 && computeBit(i) + computeBit(j) <= k) {
            count++;
            vis[i][j] = 1;
        } else {
            vis[i][j] = 1;
            return;
        }
        for (int t = 0; t < 4; t++) {
            int x = i + move_x[t];
            int y = j + move_y[t];
            if (x >=0 && x < m && y >= 0 && y < n) {
                dfs(m, n, k, x, y, vis);
            }
        }
    }

};
```