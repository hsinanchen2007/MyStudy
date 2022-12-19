### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool map[100][100];
    int movingCount(int m, int n, int k) {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                map[i][j] = 0;
        return dfs(0, 0, m, n, k);
    }
    int dfs(int x, int y, int m, int n, int k) {
        if (map[x][y] == 1 || x < 0 || y < 0 || x >= m || y >= n || (x / 10 + x % 10 + y / 10 + y % 10) > k)
            return 0;
        map[x][y] = 1;
        return dfs(x + 1, y, m, n, k) + dfs(x, y + 1, m, n, k) + 1;
    }
};


```