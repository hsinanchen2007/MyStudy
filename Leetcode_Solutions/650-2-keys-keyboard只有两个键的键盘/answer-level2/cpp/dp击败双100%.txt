### 解题思路
对于每一个位置的字符，可以由前i位字符粘贴过来得到，所以dp[j] = min(dp[j - i] + 1, dp[j])，我们可以通过改变这个i的值来求得最小值，需要注意的是：不是每一种i都可以得到结果，所以只有符合条件的i我们才进行计算。

### 代码

```cpp
class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        int dp[n + 1] = {0};
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2 ; i <= n ; ++i)
        {
            dp[i] = dp[i - 1] + 1;
        }
        for(int i = 2 ; i <= n / 2; ++i)
        {
            if(n % i == 0)
            {
                dp[i] += 1;
                for(int j = i * 2 ; j <= n ; j += i)
                {
                    if(j % i == 0)
                        dp[j] = min(dp[j - i] + 1, dp[j]);
                }
            }
        }
        return dp[n];
    }
};
```