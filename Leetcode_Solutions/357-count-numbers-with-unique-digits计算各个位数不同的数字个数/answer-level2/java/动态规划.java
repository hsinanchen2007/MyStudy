### 解题思路
dp数组代表当前位数中最多的不同数字的个数。那么就可以初始化当位数为0，1的两个值。
然后就可以使用动态规划的思想接着往后地推。
首先3位数[0, 999]，必定包含了[0, 99]。所以dp[i] = dp[i+1] + ...的
然后再判断再三位数中的选择。
然后就是排列组合的思想了。选取前两位中没有的数字。

### 代码

```java
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 10;
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 10;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + (dp[i-1] - dp[i-2]) * (10 - (i - 1));
        }
        return dp[n];
    }
}
```