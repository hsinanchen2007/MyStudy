### 解题思路

动态规划还不是非常熟练，推导出了$f(n) = min{f(n-c[0]), f(n-c[1]) \dots f(n-c[n-])} + 1$，但具体代码实现还需加强。

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int upperLimit = amount + 1;
        vector<int> result(amount + 1, upperLimit);
        result[0] = 0;
        for(int i = 1; i < upperLimit; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i >= coins[j]) 
                    result[i] = ((result[i - coins[j]] + 1) < result[i]? (result[i - coins[j]] + 1):result[i]);
            }
        }
        return result[amount] > amount ? -1:result[amount];
    }
};
```



