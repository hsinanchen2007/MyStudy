### 解题思路
主要思路其实就是找到升序的区间，这个区间就是最佳的买入卖出区间，找到所有升序的区间即可

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int left = 0;
        while(left < prices.size()){
            int right = left+1;
            while(right < prices.size() && prices[right-1] <= prices[right])
                ++right;
            if(right == prices.size()){
                res += prices[right-1] - prices[left];
                break;
            }
            res += prices[right-1] - prices[left];
            left = right;
        }
        return res;
    }
};
```