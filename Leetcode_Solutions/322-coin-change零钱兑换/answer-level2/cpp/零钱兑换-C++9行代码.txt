### 解题思路
动态规划四要素：
1. 确定状态 
    状态表示f[i] 表示当钱为i时候，最少需要多少枚硬币
2. 状态转移方程
    f[i] = min(f[j-硬币1]+1, f[j-硬币2]+1, ... f[j-硬币k]+k)
3. 初始条件 与边界条件
    f[0] = 0 边界全为inf
4. 计算顺序
    从小到大



### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<long> f(amount+1, INT_MAX);
        
        f[0] = 0;
        for (int i = 1; i <= amount; i ++){
            for (auto j : coins){
                if (i >= j)
                    f[i] = min(f[i], f[i-j] + 1);
            }
        }
        //cout << f[amount] << endl;
        return f[amount] == INT_MAX ? -1 : f[amount];
    }
};
```