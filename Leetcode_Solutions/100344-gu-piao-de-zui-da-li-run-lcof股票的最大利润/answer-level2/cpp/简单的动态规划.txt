
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxprofit=0,lowinput=INT_MAX;//分别代表最大利润和最小成本
        for(int price:prices)
        {
            maxprofit=max(maxprofit,price-lowinput);
            lowinput=min(price,lowinput);
        }
        return maxprofit;
    }
};
```