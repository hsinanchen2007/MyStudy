### 迭代DP
```C++
#define INF 0x3f3f3f3f
const int MAXN = 1e5 + 50;
int dp[MAXN];
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        for(int i = 0; i <= amount; i++) dp[i] = INF;
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
            for(auto cur : coins)
                if(i - cur >= 0) dp[i] = min(dp[i], dp[i - cur] + 1);
        if(dp[amount] == INF)
            return -1;
        else 
            return dp[amount];
    }
};
```
### 记忆化搜索
```c++
#define INF 0x3f3f3f3f
const int MAXN = 1e5 + 50;
int dp[MAXN];
class Solution {
public:
    vector<int> money;
    int dfs(int n){
        if(n == 0) return 0;
        if(n < 0) return -1;
        if(dp[n] != INF) return dp[n];
        int MIN_ = INF;
        for(auto cur : money){
            int res = dfs(n - cur);
            if(res >= 0 && res < MIN_){
                MIN_ = res;
            }
        }
        dp[n] = MIN_ == INF ? -1 : MIN_ + 1;
        return dp[n];
    }
    int coinChange(vector<int>& coins, int amount) {
        this->money = coins;
        int n = coins.size();
        for(int i = 0; i <= amount; i++) dp[i] = INF;
        dp[0] = 0;
        return dfs(amount);
    }
};
```
