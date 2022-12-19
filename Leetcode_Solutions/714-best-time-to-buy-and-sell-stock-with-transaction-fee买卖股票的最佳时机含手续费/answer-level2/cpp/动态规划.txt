### 解题思路
这道题目最开始的时候考虑使用贪心的方法进行求解，找升序列，但是最后发现这样会错过一些最优解。看了题解的里面的讲解，发现将天数和状态利用动态规划的思想进行求解是最合理的解法。从前往后进行，前一天结束之后手里面是又还是没有股票和今天是有关系的。最后返回的值显然就是最后一天手里面没有股票的场景。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>> dpPrice(prices.size(), vector<int> (2, INT_MIN));
    dpPrice[0][0] = 0;
    dpPrice[0][1] = -(fee + prices[0]);
    for (int i = 1; i < prices.size(); i++) {
        dpPrice[i][0] = max(dpPrice[i - 1][0], dpPrice[i - 1][1] + prices[i]);
        dpPrice[i][1] = max(dpPrice[i - 1][1], dpPrice[i - 1][0] - prices[i] - fee);
    }
    return max(dpPrice[prices.size() - 1][0],dpPrice[prices.size() - 1][1]);
}
};
```