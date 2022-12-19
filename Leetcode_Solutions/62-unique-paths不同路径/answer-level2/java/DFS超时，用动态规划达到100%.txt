### 解题思路
最开始使用DFS，超时，后面优化了一下，也还是有部分测试用例无法通过，害。

### 代码

```java
class Solution {
//动态规划
    public int uniquePaths(int m, int n) {
       int[][] dp = new int[m][n];
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
//dfs
    private void dfs(int i,int j,int m,int n,int[] res){
        if (i > m || j > n)
            return;
        if (i == m || j == n){
            res[0]++;
        }
        else {
            dfs(i,j+1,m,n,res);
            dfs(i+1,j,m,n,res);
        }
    }
}
```