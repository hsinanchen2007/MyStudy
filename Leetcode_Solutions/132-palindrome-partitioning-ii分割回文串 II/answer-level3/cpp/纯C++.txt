### 解题思路
纯C++

### 代码

```cpp
class Solution {
public:
    int minCut(string s) {
        const int length = s.length();
        vector<vector<bool>> volid(length, vector<bool>(length, true));
        vector<int> dp(length, length);

        for (int step = 2; step <= length; step++)
        {
            for (int left = 0, right = left + step - 1; right <= length - 1; left++, right++)
            {
                volid[left][right] = (s[left] == s[right] && volid[left + 1][right - 1]);
            }
        }

        for (int right = 0; right <= length - 1; right++)
        {
            if (volid[0][right])
            {
                dp[right] = 0;
                continue;
            }

            for (int left = 0; left <= right; left++)
            {
                if (volid[left][right])
                {
                    dp[right] = min(dp[right], dp[left - 1] + 1);
                }
            }
        }

        return dp[length - 1];
    }
};
```