### 解题思路
用动态规划的思路，`dp[i] = max(dp[i], dp[j] * dp[i - j])`

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;    // 如果绳子长度为2,只能分成1*1
        if(n == 3) return 2;    // 如果绳子长度为3,只能分成1*2

        int dp[n + 1] = {0};    // 考虑动态规划，用dp[i]表示长度为i的绳子被切后乘积最大值
        dp[0] = 0;  
        dp[1] = 1;
        dp[2] = 2; 
        dp[3] = 3;
        for(int i = 4; i <= n; ++i){
            for(int j = 1; j <= i / 2; ++j){
                // dp[i]表示长度为i的绳子被切后乘积最大值
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[n];
    }
};
```
### 解题思路
贪心，当绳子长度大于等于5时把绳子尽可能分成长度为3的段，当绳子长度为4时将绳子分成2*2 
```
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;    // 如果绳子长度为2,只能分成1*1
        if(n == 3) return 2;    // 如果绳子长度为3,只能分成1*2
        if(n == 4) return 4;

        int numsOf3 = n / 3;

        if(n % 3 == 1){
            // 说明最后会剩下一个4,这时要把4拆分成2*2
            return pow(3, (numsOf3 - 1)) * 4;
        }
        else if(n % 3 == 2){
            // 说明最后会剩下一个2
            return pow(3, numsOf3) * 2;
        }
        return pow(3, numsOf3);
        
    }
};
```