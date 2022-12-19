### 解题思路
这种极值问题首先想到的是回溯  但是回溯超时...
那就走动态规划 状态转移方程: dp[i] = Math.min(dp[i], dp[i-1]) + cur.get(i);

需要注意的是 dp[i]是不能直接赋值的  因为在dp[i+1]中需要用到原来的dp[i]
所以需要用变量prev来保存它 然后在计算dp[i+1]的时候再把prev赋给dp[i]

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        // 即i只能与i和i+1的相加  回溯
        // 结果回溯超时  那么就只能走动态规划
        // dp[i] = Math.min(dp[i], dp[i-1]) + cur.get(i);
        int[] dp = new int[triangle.size()];
        dp[0] = triangle.get(0).get(0);
        for (int i = 1; i < triangle.size(); i++) {
            List<Integer> cur = triangle.get(i);
            // 其中第一个和最后一个 永远是继承上一个值
            int prev = dp[0] + cur.get(0); // 这是dp[j-1]的真实值
            for (int j = 1; j < i; j++) {
                // 使用prev变量保存dp[j-1] 防止其在下一次计算中已经被改变
                int tmp = prev;
                prev = cur.get(j) + Math.min(dp[j - 1], dp[j]);
                dp[j - 1] = tmp;
            }
            dp[i] += (cur.get(i) + dp[i - 1]);
            dp[i - 1] = prev;
        }
        int min = 0x7fffffff;
        for (int i : dp) {
            min = Math.min(min, i);
        }
        return min;
    }
}
```