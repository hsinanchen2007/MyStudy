### 解题思路
此处撰写解题思路
1、设置两个变量来存储最低售价和最大利润：
min_price:最低售价；
max_profit:最高利润；
2、遍历整个数组，实时更新min_price和max_profit;
3、返回最终的最大利润即可。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        int min_price = INT_MAX; //存储最低售价
        int max_profit = 0; //存储最高利润
        for(int i = 0; i < size; i++)
        {
            min_price = min(prices[i], min_price); //更新最低售价
            int profit = prices[i] - min_price; //计算利润
            max_profit = max(profit, max_profit); //跟新最高利润
        }
        return max_profit;
    }
};
```