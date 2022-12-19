### 解题思路
只要价格比前一天高，就把所有差价加起来就可以了。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Profit=0,maxProfit=0;
         if(prices.size()==0)
            return 0;
         else
         {
            for(int i=0;i<prices.size()-1;i++)
            {
             if(prices[i]<=prices[i+1])
             {
                 Profit=prices[i+1]-prices[i];
                 maxProfit=maxProfit+Profit;
             }
            }
        }
    return maxProfit;
    }
};
```