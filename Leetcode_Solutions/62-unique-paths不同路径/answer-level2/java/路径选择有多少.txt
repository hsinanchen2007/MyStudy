### 解题思路
此处撰写解题思路
一开始使用组合数学进行计算发现容易超出int范围，然后就只能使用动态规划的方法，这道题和求左上端点到右下端点的最短路径有些类似；初始化第一行第一列为1，表示如果从第一行一直向右，那么最后只能一直向下，同理如果一开始一直向下，那最后只能一直向右。那么最后总的情况应该是向下的每个位置的选择加上向右的每个位置的选择。
### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j  ==0)
                    dp[i][j] = 1;
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
    
}
```