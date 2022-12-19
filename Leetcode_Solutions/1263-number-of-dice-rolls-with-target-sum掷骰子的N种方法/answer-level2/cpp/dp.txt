### 解题思路
本质还是一个填表的过程，d个骰子，f点，所以最多可以凑到d*f，我们枚举每一个骰子加入时产生的变化。比如说现在在填10这个位置的，我们从1开始枚举当前骰子，10-1=9，那么我们可以和之前所有骰子凑成的9加一个当前的1得到10，所以我们当前得到10的种类就是之前所有骰子凑成9的种类，然后到2，10-2=8，我们可以和之前所有骰子凑成的8加一个当前的2得到10，所以可以凑成10的种类要再加一个之前所有骰子凑成8的种类数，依次进行。

### 代码

```cpp
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int dp[d + 1][1000] = {0};
        for(int i = 1 ; i <= f ; ++i)
            dp[1][i] = 1;
        int mod = 1000000000 + 7;
        for(int i = 2 ; i <= d ; ++i)
        {
            for(int k = 1 ; k <= f ; ++k)
            {
                for(int j = k + 1 ; j <= f * d ; ++j)
                {
                    dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - k] % mod) % mod;
                }
            }
        }
        return dp[d][target] % mod;
    }
};
```