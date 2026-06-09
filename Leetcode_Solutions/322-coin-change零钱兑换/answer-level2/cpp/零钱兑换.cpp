### 解题思路
此处撰写解题思路

### 代码
暴力递归超时辣
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res=INT_MAX;
        help(coins,amount,res,0);
        return res == INT_MAX ? -1 : res;
    }
    void help(vector<int>&coins,int amount,int &res,int count){
        if(amount == 0){
            if(count < res)
                res = count;
            return;
        }
        if(amount < 0)
            return;
        for(int i = 0;i < coins.size();i++){
            amount -= coins[i];
            help(coins,amount,res,count+1);
            amount += coins[i];
        }
    }
};
```


dp
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i = 1;i <= amount;i++){
            for(int j = 0;j < coins.size();j++){
                if(i < coins[j])
                    continue;
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};
```