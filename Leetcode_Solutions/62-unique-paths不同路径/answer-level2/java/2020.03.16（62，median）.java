### 解题思路
本题是第一次使用**动态规划（dp）**解题

动态方程很重要：dp[i][j] = dp[i-1][j] + dp[i][j-1]

这里还优化了下，用一个数组来完成，主要思想是用上一行求出的 j 加上当前行的 j-1 即为最终路径

又因为右下角终点位置只能由他**上边**或**左边**的**一个方向**到达，故初始化他们值都为1即可。

### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[] cur = new int[n];//定义当前数组
        Arrays.fill(cur,1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                cur[j] += cur[j - 1];//上一行的j加上当前行的j-1
            }
        }
        return cur[n - 1];
    }
}
```