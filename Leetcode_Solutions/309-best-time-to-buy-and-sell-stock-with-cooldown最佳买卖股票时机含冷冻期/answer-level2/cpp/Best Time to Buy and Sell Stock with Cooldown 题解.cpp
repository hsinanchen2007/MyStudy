
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0){
            return 0;
        }

        int hold = INT_MIN;  // hold表示持有股票，初始状态下hold说明买入，利润为-prices[0]
        int cooldown = 0;       // cooldown表示今天刚把股票卖出去，初始状态下cooldown为0
        int free = 0;           // free表示没有持有股票，且不在cooldown期间，初始状态下为0
        for(auto &p : prices){
            int pre_cooldown = cooldown;
            cooldown = hold + p;    // cooldown只能由hold卖出之后转移过来
            hold = max(hold, free - p);     // hold，可能之间就hold，也可能之前free然后买入之后hold
            free = max(free, pre_cooldown);     // free，可能之前就free，也可能从cooldown转移过来
        }

        return max(free, cooldown);     // 最后必然不可能hold
    }
};
```