

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        vector<int> dp(prices.size(),0);
        int minPrice=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            dp[i]=max(dp[i-1],prices[i]-minPrice);
            if(minPrice>prices[i])
                minPrice=prices[i];
        }

        return *(--dp.end());
    }
};
```