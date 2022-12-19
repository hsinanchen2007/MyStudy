### 解题思路
1、可以采用动态规划，将数组中两个数的最大差问题转化为差数组中最大连续子列和问题
    因为a[6] - a[3] = a[6] - a[5] + a[5] - a[4] + a[4] - a[3]
2、采用一次遍历的方法，遍历数组过程中记录遇到的最低价格和最大利润。如遇更低的价格，则更新最低价格，临时利润更新为0。
这里采用第二种方法
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int minPrice = 1000000000, maxProfit = 0, profit;
        for(int i = 0; i < len; i++){
            if(prices[i] <= minPrice){
                minPrice = prices[i];
                profit = 0;
            }else{
                profit = prices[i] - minPrice;
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};
```