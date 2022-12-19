### 解题思路
如果今天买入股票，后面会涨，就买入股票，否则不买。
如果已经买入股票，股票价格下降的前一天卖出股票。
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j=0,sum=0,k=0;//jk用于比较隔天股票是否增长
        for(int i=0;i<prices.size();)
        {
            j=i+1;
            k=i;
            for(;j<prices.size();j++)
            {
                if(prices[k]>prices[j]) break;//当股票价格跌（j）的前一天（k）卖出
                k++;
            }
            sum+=prices[k]-prices[i];
            i=j;//i就等于卖出股票（k）的第二天（j）
        }
        return sum;

    }
};
```