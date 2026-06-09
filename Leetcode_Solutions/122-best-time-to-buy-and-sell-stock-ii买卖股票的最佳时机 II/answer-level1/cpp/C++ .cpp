### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int min = prices[0];
        int max = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(min > prices[i]) {
                min = prices[i];
            } 
            else {
                max += prices[i] - min;
                min = prices[i];
            } 

        }
        return max;
    }
};
```