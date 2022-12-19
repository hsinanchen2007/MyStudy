思路和上一题完全一样, 不同之处在于
1) 使用int会溢出, 用long也会溢出, 所以使用java.math.BigInteger
2) 需要使用BigInteger中的乘法、取最大值操作、取模操作
2) 最后的返回结果需要按照题目要求取模

```java
import java.math.BigInteger;

class Solution {
    public int cuttingRope(int n) {
        if(n<2)
            return 0;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        /*
        d[i]表示长度为i的绳子剪完后各段乘积的最大值, 最终目标是dp[n]
        dp[i]可以看成是长度为i-k的绳子的最大值和长度为k的绳子的最大值的乘积, 子问题最优, 所以dp[i]也是最优
        状态转移方程: dp[i] = max(dp[i], dp[i-k]*dp[k])
        */
        //下面的初始值不同于上面的特殊情况, 上面是必须剪一刀, 下面的三个初始值不用再减了
        BigInteger[] dp = new BigInteger[n+1];
        dp[1] = new BigInteger("1");//内循环中会用到这个值
        dp[2] = new BigInteger("2");
        dp[3] = new BigInteger("3");
        for(int i=4; i<=n; i++){
            //初始化dp[i]
            dp[i] = new BigInteger("0");
            //长度为i的绳子有i-1个剪切位置; 不论i是奇数还是偶数, 只考虑前i/2个剪切位置即可, 后面的剪切位置是重复的
            for(int j=1; j<=i/2; j++){
                //因为j和i-j都小于i, 所以这是自底向上的计算方式
                dp[i] = dp[i].max(dp[j].multiply(dp[i-j]));
            }
        }
        return dp[n].mod(new BigInteger("1000000007")).intValue();
    }
}
```