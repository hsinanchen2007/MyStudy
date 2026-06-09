### 解题思路
动态规划，自下而上
递推关系：F(0) = 0; F(n) = min{F(n-c_i)} + 1;
（好慢啊）
第二遍稍微修改了一下，加了点条件，好像快了一点？
```cpp
if(F[n-coin]==MAX)
    continue;
if(F[n]==MAX)
    F[n] = F[n-coin]+1;
else
    F[n] = min(F[n], F[n-coin]+1);
```


### 代码

```cpp
class Solution {
    // 动态规划，自下而上
    // 递推关系：F(0) = 0; F(n) = min{F(n-c_i)} + 1;
public:
    int coinChange(vector<int>& coins, int amount) {
        //一些特殊情况
        if(amount == 0)
            return amount;
        if((coins.size()==1)){
            if(amount % coins[0] == 0)
                return amount/coins[0];
            else
                return -1;
        }
        
        //dp
        int MAX = amount + 1; //最多硬币个数（amount）
        vector<int> F(amount+1, MAX); //存F(n), 初始化值为MAX
        F[0] = 0; //初始化F(0)
        //依次计算F(1)到F(amount)
        for(int n = 1; n<=amount; n++){
            for(int coin : coins){
                if(coin <= n){
                    F[n] = min(F[n], F[n-coin]+1);   //F(n) = min{F(n-c_i)} + 1;
                }
            }
        }
        // cout<<F[amount]<<endl;
        if(F[amount]>amount)
            return -1;
        return F[amount];
    }
};
```


### 第二版代码
```cpp
class Solution {
    // 动态规划，自下而上
    // 递推关系：F(0) = 0; F(n) = min{F(n-c_i)} + 1;
public:
    int coinChange(vector<int>& coins, int amount) {
        //一些特殊情况
        if(amount == 0)
            return amount;
        if((coins.size()==1)){
            if(amount % coins[0] == 0)
                return amount/coins[0];
            else
                return -1;
        }
        
        //dp
        int MAX = amount + 1; //最多硬币个数（amount）
        vector<int> F(amount+1, MAX); //存F(n), 初始化值为MAX
        F[0] = 0; //初始化F(0)
        //依次计算F(1)到F(amount)
        for(int n = 1; n<=amount; n++){
            for(int coin : coins){
                if(coin <= n){
                    if(F[n-coin]==MAX)
                        continue;
                    if(F[n]==MAX)
                        F[n] = F[n-coin]+1;
                    else
                        F[n] = min(F[n], F[n-coin]+1);   //F(n) = min{F(n-c_i)} + 1;
                }
            }
        }
        // cout<<F[amount]<<endl;
        if(F[amount]>amount)
            return -1;
        return F[amount];
    }
};
```

