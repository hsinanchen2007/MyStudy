### 解题思路
1. 动态规划
2. DFS

### 代码

```c++ []
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 两种解法：DFS或者动态规划
        // 定义f[i][j]表示到达坐标(i,j)的不同路径数量
        if(m==0 || n==0)
            return 0;

        vector<vector<int>> f = vector<vector<int>>(m, vector<int>(n, 0));
        f[0][0] = 1;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i==0 && j>0)
                    f[i][j] = f[i][j-1];
                else if(j==0 && i>0)
                    f[i][j] = f[i-1][j];
                else if(i>0 && j>0)
                    f[i][j] = f[i-1][j]+f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }


};
```
```java []
class Solution {
    public int uniquePaths(int m, int n) {
        // TLE at (23, 12)
        if(m==0 || n==0)
            return 0;
        R = m;
        C = n;
        vis = new boolean[R][C];
        dfs(0, 0);
        return res;
    }

    private void dfs(int x, int y){
        vis[x][y] = true;
        if(x == R-1 && y == C-1){
            res++;
            return;
        }

        for(int []d: dirs){
            int nx = x+d[0];
            int ny = y+d[1];
            if(inArea(nx, ny) && !vis[nx][ny]){
                dfs(nx, ny);
                vis[nx][ny] = false;
            }
        }
    }

    private boolean inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }

    private int res = 0;
    private int R, C;
    private int[][] dirs = {{1, 0}, {0, 1}};
    private boolean[][] vis; 
}
```
```python []
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m==0 or n==0:
            return 0

        f = [[0 for _ in range(n)] for _ in range(m)]
        f[0][0] = 1

        for i in range(m):
            for j in range(n):
                if i==0 and j>0:
                    f[i][j] = f[i][j-1]
                elif j==0 and i>0:
                    f[i][j] = f[i-1][j]
                elif i>0 and j>0:
                    f[i][j] = f[i-1][j]+f[i][j-1]

        return f[m-1][n-1]
```