### 解题思路
动态规划，参考[【n个骰子的点数】：详解动态规划及其优化方式](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/nge-tou-zi-de-dian-shu-dong-tai-gui-hua-ji-qi-yo-3/)

### 代码

```cpp
class Solution {
public:
    vector<double> twoSum(int n) {
        int dp[12][67];     // dp[n][k]表示第n个骰子下掷出和为k，n<=11, k<=66
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= 6; ++i){
            dp[1][i] = 1;   // 当投掷骰子的个数为1时，和为i的个数都是1
        }

        for(int i = 2; i <= n; ++i){
            // 骰子的个数从2到n
            for(int j = i; j <= i*6; ++j){
                // 因为i个骰子最小值为i，最大值为6*i
                for(int k = 1; k <= 6; ++k){
                    // 如果要出现和为k，在第i次投掷的时的结果如果为k，那么要出现和为j的情况，就得要求第i-1次投掷的和为j-k
                    if(j - k <= 0){
                        break;
                    }
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        int all = pow(6, n);    
        vector<double> res;
        for(int i = n; i <= n*6; ++i){
            res.push_back(dp[n][i] * 1.0 / all);
        }

        return res;
    }
};
```