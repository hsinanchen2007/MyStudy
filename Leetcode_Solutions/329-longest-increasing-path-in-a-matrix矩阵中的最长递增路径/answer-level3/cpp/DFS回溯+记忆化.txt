### 解题思路

思路：记忆化回溯

1、对矩阵中每个点做路径遍历，找到最大递增路长度
2、这一类问题一般情况下用普通DFS肯定会超时的，所以通过记忆化来提高效率，设定mem[i][j]表示从当前位置[i][j]时出发所能得到的最长递增路径
3、记忆化套路

```cpp
int dfs(mem) {
    if (mem) {return xxx};

    int val = xxx;
    for (xxx) {
        // 条件满足时处理 并保存值
        val = xxx(val, dfs(mem));
    }

    // 记忆化存储
    mem = val + xxx;
}
```

40ms 16.2M
--- wangtao HW-2020/3/8

### 代码

```cpp
class Solution {
public:
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> mem;

    int dfs(vector<vector<int>>& matrix, int r, int c, int R, int C)
    {
        if (mem[r][c] != -1) {
            return mem[r][c];
        }
        int maxlen = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + d[i][0];
            int nc = c + d[i][1];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && matrix[nr][nc] > matrix[r][c]) {
                maxlen = max(maxlen, dfs(matrix, nr, nc, R, C));
            }
        }
        return mem[r][c] = maxlen + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        int R = matrix.size();
        int C = matrix[0].size();
        int maxlen = INT_MIN;
        mem = vector<vector<int>>(R, vector<int>(C, -1));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                maxlen = max(maxlen, dfs(matrix, i, j, R, C));
            }
        }
        return maxlen;
    }
};
```