### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int ans = 0;
    int f[100];
    int g[100][100];
    int dirs[5] = {0, -1, 0, 1, 0};
    int k, m, n;
    int movingCount(int _m, int _n, int _k) {
        m=_m;
        n=_n;
        k = _k;
        memset(g, 0, sizeof g);
        memset(f, 0, sizeof f);
        for (int i = 1; i <100; i++)f[i] = i %10 + f[i/10];
        dfs(0, 0);
        return ans;
    }

    void dfs(int i, int j){
        if (f[i] + f[j] > k) return;
        if (g[i][j]) return;
        g[i][j] = 1;
        ans++;
        for (int d = 0; d < 4; d++){
            int x = i + dirs[d], y = j+ dirs[d+1];
            if (x >=0 && x < m && y>=0 && y< n && !g[x][y]){
                dfs(x, y);
            }
        }
    }
};
```