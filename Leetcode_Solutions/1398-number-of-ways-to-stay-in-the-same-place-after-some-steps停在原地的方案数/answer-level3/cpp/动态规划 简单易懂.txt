寻找方案数，直观想到动态规划。

对应的状态转移也比较简单：到达索引0处只有两种情况，前一时刻在索引1，或者前一时刻在索引0，因此只要使用长度为arrLens的数组保存每个位置的状态，每执行一次操作，对应更新每一时刻的状态即可。

需要注意的地方，由于arrLen的可能范围很大，导致O(arrLen * steps)的时间复杂度可能会超时，需要一些优化，即对动态规划的状态数组做裁剪。

关键思路是：经过n步之后，能到达索引0处的指针，最远的初始位置只有可能在索引n-1处。另外，由于初始位置在索引0处，因此经过steps次操作后，索引最远也只能落在steps处。

因此状态数组的长度可以由arrLens缩短为 min(steps, arrLens)。



```c++
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1000000007;
        vector<int> dp(min(steps, arrLen)), pre;
        dp[0] = 1;
        pre = dp;
        while (steps--) {
            for (int i = 0; i < dp.size(); ++i) {
                if (i > 0) {
                    dp[i] += pre[i - 1];
                    dp[i] %= mod;
                }
                if (i < dp.size() - 1) {
                    dp[i] += pre[i + 1];
                    dp[i] %= mod;
                }
            }
            pre = dp;
        }
        return dp[0];
    }
};
```