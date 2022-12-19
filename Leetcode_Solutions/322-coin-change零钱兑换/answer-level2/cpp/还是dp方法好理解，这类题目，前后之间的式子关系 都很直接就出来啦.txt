### 解题思路

一开始 我一直都没理解。我还想着，为什么不嫌预处理ans那个数组呢，就是把ans[coins[i]]=1;为什么不这样操作一下呢，还有为啥要加一呢，我一直没理解。就来，明白过来了。一开始ans都是0 。开始循环之后，当前ans[i]如果能通过i-coins[j]的方式得到一个值。即使ans[coins[j]]的值是0，也没事，因为说明有coins[j]这种硬币，直接加一就好啦。不需要管他那么多，还有就是 也不用先排序。直接在循环里 接一个判断就好啦。 很有收获，开心
### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount + 1, 0);
        for(int i = 1; i <= amount; i++){
            int minnum = 0x3f3f3f3f;
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] < 0){
                    continue;
                }
                int temp = ans[i - coins[j]];
                    minnum = min(minnum, temp);
                
                
            }
            ans[i]  = minnum + 1;
        }
        if(ans[amount] == 0x3f3f3f3f + 1){
            return -1;
        } else {
            return ans[amount];
        }
        
    }
};
```