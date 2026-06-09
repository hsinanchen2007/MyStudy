和剪绳子1相似，只是n值较大会溢出，Python处理大数不需要特殊处理，Java需要使用BigInteger，取余需要在最后进行，在循环内部会由于取余取最大值错误
主要是有个规律，绳子被分割成尽量小（2,3）乘积会最大，类似于一个整数拆成两个尽量靠近的数乘积最大，个人觉得应该是有个严格的数学证明
```
import java.math.BigInteger;
class Solution {
    public int cuttingRope(int n) {
        if (n==2) {
            return 1;
        } else if (n==3) {
            return 2;
        } else if (n==4) {
            return 4;
        } else if (n==5) {
            return 6;
        }

        BigInteger[] dp=new BigInteger[n+1];
        dp[3]=new BigInteger("2");
        dp[4]=new BigInteger("4");
        dp[5]=new BigInteger("6");
        dp[6]=new BigInteger("9");
        BigInteger m=new BigInteger("1000000007");
        
        for (int i=7;i<=n;i++) {
            BigInteger a=new BigInteger("2").multiply(dp[i-2]);
            BigInteger b=new BigInteger("3").multiply(dp[i-3]);
            dp[i]=a.max(b);
        }
        return dp[n].mod(m).intValue();
    }
}
```
