### 解题思路
子问题：在点(i, j)有多少种方法到达；
状态方程：在点(i, j)有x种方法到达，p(i, j)
状态转移方程：p(i, j) = p(i-1, j)+p(i, j+1)(条件满足的情况下)
初始化:p(i, 0) = 1, p(0, j) = 1

### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
       
        int[][] p = new int[m][n];
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (i == 0 || j == 0) {
                    p[i][j] = 1;
                    continue;
                }
                p[i][j] = p[i-1][j] + p[i][j-1];
            }
        }
        return p[m-1][n-1];
    }
}
```