### 解题思路
后半句话比较难想。

### 代码

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        int dp[num + 1];
        dp[0] = 0;
        ans.push_back(dp[0]);
        if(num == 0)
        return ans;
        dp[1] = 1;
        ans.push_back(dp[1]);
        if(num == 1)
        return ans;
        dp[2] = 1;
        ans.push_back(dp[2]);
        if(num == 2)
        return ans;
        int cnt = 2;
        for(int i = 3 ; i <= num ; ++i)
        {
            if(i % 2 == 0)
            {
                if(pow(2, cnt) == i)
                {
                    dp[i] = 1;
                    cnt++;
                }
                 else
                 dp[i] = dp[i / 2];
            }
            else
                dp[i] = dp[i - 1] + 1;
            ans.push_back(dp[i]);
        }
    return ans;

    }
};
```