简单的动态规划，但是为啥空间消耗这么多？
```
class Solution {
    public int numTrees(int n) {
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i <= n;i++)
        {
            for(int j = 0;j < i;j++)
            {
                dp[i] = dp[i] + dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
}
```
![图片.png](https://pic.leetcode-cn.com/6ca1df0dfb973b112f9e86ae4741f4e9dab8b5f7c02b949305b4a90e165722e1-%E5%9B%BE%E7%89%87.png)

