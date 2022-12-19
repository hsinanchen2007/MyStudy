### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> record(amount + 1, amount+1);
        record[0] = 0;
        for (int i = 0; i < record.size(); i++){
            for (int c : coins){
                 if (i -c < 0) continue;
                record[i] = min(record[i], 1 + record[i - c]);
            }
        }
    return (record[amount] == amount+1) ? -1 : record[amount];
    }
};

```