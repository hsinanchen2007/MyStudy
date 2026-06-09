### 解题思路
题目要求是在某一日买入，然后在之后的某一日卖出，求买入卖出的最大利润。
贪心法：假设当前卖出的最大价格max_price为数组的最后一个值，从后往前遍历，从倒数第二个值开始，计算收益profit = max_price - 当前买入价格；如果profit < 0, 更新最大卖出价格max_price为当前买入价格；如果profit比之前的最大利润值大，则更新最大利润（result）为profit。
![捕获.JPG](https://pic.leetcode-cn.com/b0a08ad7be1ecc700a7222b1fd1ce42dae50d30f6f67e3c313cb4506f26c63d8-%E6%8D%95%E8%8E%B7.JPG)


### 代码

```cpp
class Solution {
public:
    // 贪心法
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int n = prices.size();
        if (n >= 2) {
            int max_price = prices[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                int profit = max_price - prices[i];
                if (profit <= 0) {
                    max_price = prices[i];
                } else if (profit > result) {
                    result = profit;
                }
            }
        }
        return result;
    }
};
```