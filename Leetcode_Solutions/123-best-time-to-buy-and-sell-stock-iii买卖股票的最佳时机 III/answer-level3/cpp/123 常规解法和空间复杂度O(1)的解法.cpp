方法一
```
//常规解法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0)
            return 0;
        int profit[size][3][2];
        profit[0][1][0] = 0;
        profit[0][1][1] = -prices[0];
        profit[0][2][0] = 0;
        profit[0][2][1] = -prices[0];
        for (int i=1; i<size; i++) {
                profit[i][1][0] = max(profit[i-1][1][0], profit[i-1][1][1]+prices[i]);
                profit[i][1][1] = max(profit[i-1][1][1], -prices[i]);
                profit[i][2][0] = max(profit[i-1][2][0], profit[i-1][2][1]+prices[i]);
                profit[i][2][1] = max(profit[i-1][2][1], profit[i-1][1][0]-prices[i]);
        }
        return profit[size-1][2][0];
    }
};
```
方法二
```
//空间复杂度O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0)
            return 0;
        int p_i_1_0 = 0,
            p_i_1_1 = INT_MIN,
            p_i_2_0 = 0,
            p_i_2_1 = INT_MIN;
        for (int i=0; i<size; i++) {
            p_i_2_0 = max( p_i_2_0, p_i_2_1+prices[i]);
            p_i_2_1 = max( p_i_2_1, p_i_1_0-prices[i]);
            p_i_1_0 = max( p_i_1_0, p_i_1_1+prices[i]);
            p_i_1_1 = max( p_i_1_1, -prices[i]);
        }
        return p_i_2_0;
    }
};
```

