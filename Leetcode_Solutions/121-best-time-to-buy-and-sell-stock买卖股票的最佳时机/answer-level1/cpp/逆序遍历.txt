### 解题思路
逆序遍历一遍找到最大的利润
时间复杂度o(n), 空间复杂度o(1),因为只用到了常数个额外变量

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, maxP = 0;
        for(size_t i = prices.size() - 1; i + 1 > 0; i--){
            if(max - prices[i] > maxP){
                maxP = max - prices[i];
            }
            if(prices[i] > max){
                max = prices[i];
            }    
        } 
        return maxP;
    }
    
};
```