
#题解:
   本道题利用动态规划的思路会比较简单，时间复杂度O(n).存储的变量主要是result记录总的收益，buy记录当前状态下为买的最佳收益，sell记录当前状态为卖的最佳收益。buy取上次买状态的总收益和这次如果买的总收益的最大值。sell取上次卖状态和这次如果卖的总收益的最大值。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        int buy = -prices[0];
        int sell = 0;
        int result = 0 ;
        for(int i = 1; i<prices.size() ; i++){
            buy = max(buy,sell - prices[i]);
            sell = max(sell,buy + prices[i]);
            result = max(result, sell);        
        }
        return result;
    }
};
```