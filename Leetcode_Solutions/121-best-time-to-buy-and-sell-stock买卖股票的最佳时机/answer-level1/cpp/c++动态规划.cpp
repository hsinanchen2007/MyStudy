### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //初始动态表
    vector<int> dp(prices.size());
    //base case
    if(prices.size() == 0){
        return 0;
    }
    //第一天买第一天卖
    dp[0] = 0;
    int minPrice = prices[0];
    for(int i = 1; i < prices.size();i++){
        //转化式为当前天数不操作，或者当前天数卖出股票
        minPrice = min(minPrice,prices[i]);
        dp[i] = max(dp[i-1],prices[i]-minPrice);
    }
    return dp[dp.size()-1];
    }
};
```