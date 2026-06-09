```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int base = INT_MAX;
        for (const int &price: prices) {
            base = min(base, price);
            profit = max(profit, price-base);
        }
        return profit;
    }
};
```