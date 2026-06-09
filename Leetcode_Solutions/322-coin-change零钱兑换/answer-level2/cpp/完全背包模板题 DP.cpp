### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>f(amount + 1, 0xfff);
        f[0] = 0;
        for(int i = 0; i< coins.size(); i++) {
            for(int j = coins[i]; j<= amount; j++) {
                f[j] = min(f[j], f[j - coins[i]] + 1);
            }
        }

        if(f[amount] == 0xfff) return -1;
        return f[amount];
    }
};
```