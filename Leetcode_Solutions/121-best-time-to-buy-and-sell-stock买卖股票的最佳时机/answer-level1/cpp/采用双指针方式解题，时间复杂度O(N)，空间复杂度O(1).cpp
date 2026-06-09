```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 双指针
        int res = 0, min_pos = 0, max_pos = 0;
        for (int index = 1; index < prices.size(); ++index) {
            if (prices[index] < prices[min_pos]) {
                min_pos = index;
            } else if (prices[index] > prices[min_pos] && prices[index] - prices[min_pos] > res) {
                max_pos = index;
            }
            if (max_pos > min_pos) {
                res = prices[max_pos] - prices[min_pos];
            }
        }
        return res;
    }
};
```
