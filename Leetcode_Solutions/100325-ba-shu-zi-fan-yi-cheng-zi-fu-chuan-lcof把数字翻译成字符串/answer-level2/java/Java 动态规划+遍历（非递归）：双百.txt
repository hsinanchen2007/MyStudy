动态规划
![1585056259(1).jpg](https://pic.leetcode-cn.com/7bf091451f91100edc17eb3656e4deec83cd1c5d0350719c602f10412036a8a1-1585056259\(1\).jpg)


1. 如果第i个数能和第i-1个数组成翻译： dp[i] = dp[i-1] + dp[i-2]
2. 反之：dp[i] = dp[i-1]
```
class Solution {
    public int translateNum(int num) {
        String s = String.valueOf(num);
        int len = s.length();
        int[] dp = new int[len+1];
        dp[1] = 1;
        dp[0] = 1;
        for(int i = 2; i<len+1; i++){
            int temp = Integer.valueOf(s.substring(i-2,i));
            if(temp > 9 && temp < 26 ){
                dp[i] = dp[i-1] + dp[i-2];
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[len];
    }
}
```
