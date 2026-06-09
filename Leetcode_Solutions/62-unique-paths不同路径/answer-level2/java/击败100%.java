### 解题思路
动态规划套路化，本题和minimum-path-sum思路基本一样，从二维数组右下角的节点开始处理
![image.png](https://pic.leetcode-cn.com/4f70e2849837ed2a77c08bb5584ee8872c8de27bdb9e0495d94f60d9de3cfefa-image.png)


### 代码

```java
public class Solution {
    public int uniquePaths(int m, int n) {
        if(m < 2 || n < 2)
            return 1;
        int[][] dp = new int[m][n];
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i == m - 1 && j == n - 1)
                    dp[i][j] = 0;
                else if(i == m - 1)
                    dp[i][j] = 1;
                else if(j == n - 1)
                    dp[i][j] = 1;
                else{
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
}
```