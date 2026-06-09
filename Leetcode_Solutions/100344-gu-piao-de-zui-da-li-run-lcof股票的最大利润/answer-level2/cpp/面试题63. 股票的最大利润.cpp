```cpp
// 一次遍历，记录最小值，最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() < 2)
            return 0;

        int minPrice = prices[0];
        int diff = 0;
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            diff = max(diff, prices[i] - minPrice);
        }
        return diff;
    }
};

```