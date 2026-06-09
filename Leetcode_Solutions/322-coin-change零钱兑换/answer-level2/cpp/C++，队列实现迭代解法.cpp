### 解题思路
队列实现层次遍历搜索
vector<bool>存储是否已经遍历过此结点，实现剪枝

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        vector<bool> visited(amount, false);
        queue<pair<int, int>> coinQueue; //利用队列实现广度优先遍历，前一个int存储当前钱数，后一个int存储当前硬币数

        coinQueue.push(make_pair(amount,0));
        visited[amount - 1] = true;

        while(!coinQueue.empty()){
            int currAmount = coinQueue.front().first;
            int numCoin = coinQueue.front().second;
            coinQueue.pop();
            for(auto coin : coins){
                if(currAmount == coin) return numCoin + 1;
                if((currAmount > coin) && !visited[currAmount - coin - 1]){
                    coinQueue.push(make_pair(currAmount - coin, numCoin + 1));
                    visited[currAmount - coin - 1] = true;
                }
            }
        }

        return -1;
    }
};
```