### 解题思路

将f(n+1)-f(n)>0的值都加起来即可
只要增长的，不要跌的


### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size()<=1)    return 0;

        int sum = 0;
        int last = prices[0];

        for(int i = 1;i<prices.size();i++)
        {
            if(prices[i]-last >0)
                sum += prices[i]-last;

            last = prices[i];  
        }

        return sum;
    }
};
```