
第k个丑数必然由第0到k-1中的某个丑数乘上2、3、5其中一个数产生，我们取乘积最小的一个。
但是你怎么知道用那个数来乘上2、乘上3、乘上5恰好得到比k-1个丑数大的数呢？难道0到k-1的丑数一个个去遍历吗？
显然不用？这个丑数序列是排好序的，每次在产生新的丑数后，如果这个数=2*dp[i],则当前的max2Index就必须要大于i。3和5
也是如此。但是需要注意的是，下边的往前递增的判断要注意max2index、max3index、max5index的递增不是互斥的。

```
public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        int max2index = 0;
        int max3index = 0;
        int max5index = 0;
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            dp[i] = Math.min(dp[max2index] * 2, Math.min(dp[max3index] * 3, dp[max5index] * 5));
            if (dp[i] == dp[max2index] * 2) {
                max2index++;
            }
            if (dp[i] == dp[max3index] * 3) {
                max3index++;
            }
            if (dp[i] == dp[max5index] * 5) {
                max5index++;
            }
        }
        return dp[n - 1];
    }
```
