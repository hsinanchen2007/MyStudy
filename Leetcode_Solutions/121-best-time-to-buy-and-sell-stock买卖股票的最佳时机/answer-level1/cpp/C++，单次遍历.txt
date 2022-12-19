### 解题思路
单次遍历，每次循环更新当前最小股价，和当前最大收益。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int minP = INT_MAX;
        int maxP = 0;
        for(auto i : prices){
            if(i < minP) minP = i;
            if((i - minP) > maxP) maxP = i - minP;
        }
        return maxP;
    }
};
```