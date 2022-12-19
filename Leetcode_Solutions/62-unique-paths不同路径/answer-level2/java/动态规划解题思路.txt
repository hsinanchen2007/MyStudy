### 解题思路
组合的方法其实很简单，但是正在练习动态规划，所以用动态规划的思路解题：

首先由题目得知，机器人只能向右或者向下移动，所以第一列和第一排的路径数都可以确定了，即：

dp[0][n] = 1;

dp[m][0] = 1;

然后除去第一列和第一排，中间的任何一个点的路径都等于其到达上面的一个点和左面的一个点的路径的和，所以可得：

dp[i][j] = dp[i - 1][j] + dp[i][j - 1];


 
### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        if(m < 1 || n < 1){
            return 1;
        }
        int[][] dp = new int[m][n];
        for(int temp = 0;temp < m;temp++){
            dp[temp][0] = 1;
        }
        for(int temp = 0;temp < n;temp++){
            dp[0][temp] = 1;
        }
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
}
```