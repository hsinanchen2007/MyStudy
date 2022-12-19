### 解题思路
这个路径问题中没有设置障碍，那很明显，二维数组的第一行和第一列都是1，先设置为1，后面的每一个格子都是其左边和上面之和，这样比较容易理解。

### 代码

```java
class Solution {
     public int uniquePaths(int m, int n) {
        int[][] dp= new int[m][n];
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                dp[0][j] = 1;
                dp[i][0] = 1;
            }
        }

        for (int i = 1; i < dp.length; i++) {
            for (int j = 1; j < dp[0].length; j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];

    }
}
```