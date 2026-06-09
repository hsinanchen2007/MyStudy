### 解题思路
本来想着把coins排个序，然后从面值较大的开始遍历，每次递归限制一下当前最大的面值是多少，另外还要用一个record[]数组记录一下，以防重复计算。但是这存在一个很大的问题，如果每次递归限定了当前的最大面值，那此次递归的结果并不是当前金额的最少硬币数，而是当前金额在最大面值是某个值的时候的最少硬币数。所以，每次递归还是把所有的面值都遍历一遍吧，可能因为顺序不同会有重复计算。

### 代码

```cpp
class Solution {
public:
    int f(vector<int>& coins, int left, vector<int>& record) {
        if (left < 0)
            return -1;
        if (left == 0)
            return 0;
        if (record[left - 1] != 0)
            return record[left - 1];
        
        int MIN = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int tmp = f(coins, left - coins[i], record);
            if (tmp != -1) {
                MIN = min(tmp + 1, MIN);          // tmp + 1!!!!!!!
            }
        }

        record[left - 1] = MIN == INT_MAX? -1 : MIN;
        return record[left - 1]; 
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0)
            return -1;
        if (amount == 0)
            return 0;

        vector<int> record;
        record.resize(amount);

        return f(coins, amount, record);
    }
};
```