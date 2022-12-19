1、贪心算法
原理就是数学里面的证明，这里就不贴出来了。
```
class Solution {
    public int cuttingRope(int n) {
        int max = 0;
        int temp = 1;
        int[] dp = new int[n+1];
        int[] result = new int[n];
        for(int i = 2;i<=n;i++){
            for(int k = 0;k<i;k++){
                result[k] = n/i;
            }
            if(n%i != 0){
                for(int j = 0;j<n%i;j++){
                     result[j] = result[j]+1;
                }
            }
            for(int p = 0;p<i;p++){
                temp = temp*result[p];
            }
            dp[i] = temp;
            temp = 1;
        }
        for(int i=2;i<=n;i++){
            max = Math.max(max,dp[i]);
        }
        return max;
    }
}
```

2、动态规划（动态规划的效率比贪心算法要高）
代码也很简单，就几行。
这里讲一下原理：
1、首先设置状态变量：dp[i]：代表将数字i分成m段的最大乘积。
2、寻找递推公式：我们注意找规律，动态规划里面最重要的就是这个递推公式，
我们要找的就是dp[i]与dp[i]之前的dp[i-1]、dp[i-2]...dp[2]之间的关系，
动态规划的精髓就是记忆化搜索，这是跟递归最本质的区别，所以在求dp[i]的时候肯定能用到
dp[i]之前的数据，这里我们将i分成两个部分：j 和 dp[i-j],因为dp[i-j]，是我们已经知道的
把i-j分成m段的最大乘积，要想知道dp[i]的值，我们需要尝试i次，也就是把j从1到i-1遍历，得到
j*dp[i-j]的最大值，合理地利用了以前算出来的最大值。

```
class Solution {
    public int cuttingRope(int n) {
        int max = 0;
        int[] dp = new int[n+1];
        dp[2] = 1;
        dp[1] = 0;
        for(int i = 2;i<=n;i++){
            for(int j = 1;j<i;j++){
                dp[i] = Math.max(dp[i],j*Math.max(dp[i-j],i-j));
            }
        }
        return dp[n];
    }
} 
```
