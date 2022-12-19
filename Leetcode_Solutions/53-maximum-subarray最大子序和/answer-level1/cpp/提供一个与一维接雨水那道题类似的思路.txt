```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 我们要做的其实就是低价买入，高价卖出——所以我们需要的信息是：某一天之前的最低价和某一天之后的最高价
        // 即，leftMin[size] 和 rightMax[size]
        // 这题和一维的接雨水类似，此类思想需要掌握
        // time: O(3n)  space: O(2n)
        int size = prices.size();
        if (size == 0 || size == 1) return 0;
        
        vector<int> leftMin(size);  // leftMin[i]表示第i天和第i天之前的最低价
        leftMin[0] = prices[0];
        for (int idx = 1; idx < size; ++idx)
            leftMin[idx] = leftMin[idx-1] < prices[idx] ? leftMin[idx-1] : prices[idx];
        
        vector<int> rightMax(size); // rightMax[i]表示第i天和第i天之后的最高价
        rightMax[size-1] = prices[size-1];
        for (int idx = size-2; idx >= 0; --idx)
            rightMax[idx] = rightMax[idx+1] > prices[idx] ? rightMax[idx+1] : prices[idx];
        
        int max_profit = 0;
        for (int idx = 0; idx < size; ++idx) {
            max_profit = max_profit > rightMax[idx]-leftMin[idx] ? max_profit : rightMax[idx]-leftMin[idx];
        }
        
        return max_profit;
        
        /*
        // brute force
        int max_profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = i+1; j < prices.size(); ++j) {
                if (prices[j] - prices[i] > max_profit)
                    max_profit = prices[j] - prices[i];
            }
        }
        return max_profit;
        */
    }
};
```
