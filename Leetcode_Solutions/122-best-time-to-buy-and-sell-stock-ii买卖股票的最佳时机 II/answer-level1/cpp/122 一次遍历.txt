```
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int size = prices.size();
        for (int i=0; i<size-1; i++)
            profit += prices[i+1]>prices[i] ? prices[i+1]-prices[i] : 0 ;
        return profit;
    }
};
```
