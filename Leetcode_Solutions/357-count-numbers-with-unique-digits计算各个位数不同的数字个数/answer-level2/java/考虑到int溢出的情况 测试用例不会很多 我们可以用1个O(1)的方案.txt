执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
 代码如下
```angelscript
    
public class Solution357 {
    private static  int nums[]=new int[]{1,10,91,739,5275,32491,168571,712891,2345851,5611771};
   //取巧方案
    public int countNumbersWithUniqueDigits(int n){
      
        return nums[n];
    }

    //动归解决
    public int countNumbersWithUniqueDigits1(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 9;
        int num = 10;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] * (11 - i);
            num += dp[i];
        }
        return num;
    }


```
