### 解题思路
完全背包的变种，如果用二维数组会报超内存，只能写成一维的优化方式
这个和原始的完全背包不同之处在于 只给一个维度，但是可以从这一个数扩展为完全背包，
物品价值为i*i;类似coin change
### 代码

```java
class Solution {
    public int numSquares(int n) {

        int[] dp = new int[n + 1];
        Arrays.fill(dp, n + 1);
        dp[0] = 0;
        for(int i = 1;i <= n; i++)
        {
            for(int j = i * i; j <= n; j++)
            {
                
                dp[j] = Math.min(dp[j], dp[j - i * i] + 1);

            }
        }
        return dp[n];

    }
}
```