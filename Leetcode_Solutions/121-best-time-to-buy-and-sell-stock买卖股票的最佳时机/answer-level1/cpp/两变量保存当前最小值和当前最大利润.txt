### 解题思路
1. 两个变量分别保存当前最大利润和最小价格；
2. 伴随everyday增加，依次计算；
实际是动态规划的思路


### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //用两个变量记录，当前最大利润和当前最小的变量值
        //这个其实是动态规划的思路了
        if(prices.size()<=1) return 0;
        int maxProfit = 0;
        int minPrices = prices[0];
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]-minPrices>maxProfit) 
                maxProfit=prices[i]-minPrices;
            if(minPrices>prices[i])
                minPrices=prices[i];
        }
        return maxProfit;
    }
};
```