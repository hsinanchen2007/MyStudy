### 解题思路
dp[n][sum]表示n个骰子摇出sum的有多少种情况
递推公式 dp[n][sum] = ∑dp[n-1][sum-subsum] ，subsum=[1,6] 由于一个骰子的范围在[1,6]

### 代码

```java
class Solution {
    public double[] twoSum(int n) {
        int maxsum = 6*n;
        int cap = 5*n+1;
        int[][] dp = new int[n+1][maxsum+1]; //n个骰子 摇出sum的有多少种情况
        for (int j=1;j<=6;j++) {
            dp[1][j] = 1;
        }
        for (int i=2;i<=n;i++) {// 骰子个数从小到大
            for (int j=i;j<=6*i;j++) {// 遍历sum
                for (int subsum=1;subsum<=6;subsum++) {
                    if (j-subsum>=1) {
                        dp[i][j] += dp[i-1][j-subsum];
                    }
                }
            }
        }
        // 求取比例 除以 6的n次幂
        double[] res = new double[cap];
        for (int j=n,i=0;j<=6*n&&i<cap;j++,i++) {
            res[i] = dp[n][j]*1.0/Math.pow(6, n);
        }
        return res;
    }
}
```
![image.png](https://pic.leetcode-cn.com/243d021aba8852431cfb6d1d8ba11fee8b174d9475c83f1bff086f3072963f13-image.png)
