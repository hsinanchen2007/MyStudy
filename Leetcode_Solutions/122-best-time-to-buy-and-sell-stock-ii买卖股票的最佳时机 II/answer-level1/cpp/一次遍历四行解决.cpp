每次计算相邻两个股偏差，作为收入。
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0;
        for(int i=1; i<prices.size(); ++i)
            p += max(0,prices[i]-prices[i-1]);
        return p;
    }
};
```
