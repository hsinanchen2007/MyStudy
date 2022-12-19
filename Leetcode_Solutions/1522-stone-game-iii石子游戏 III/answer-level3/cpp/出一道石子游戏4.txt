先给出我的写法。

```
int dp[50005][2]; //dp[i][j]表示的当前在第i个位置选，当前是alice/bob都选用最优策略的情况下，sum(alice)-sum(bob)的值

int visited[50005][2];

vector<int> nums;
int n;

int dfs(int cur, int turn){
    if(cur==n) return 0;
    if(visited[cur][turn]) return dp[cur][turn];
    visited[cur][turn] = 1;
    if(turn == 0){
        dp[cur][turn] = nums[cur] + dfs(cur+1, turn^1);
        int t = nums[cur];
        for(int i=cur+1; (i<=cur+2)&&(i<n); i++){
            t += nums[i];
            dp[cur][turn] = max(dp[cur][turn], t+dfs(i+1, turn^1));
        }
    }else{
        dp[cur][turn] = -nums[cur] + dfs(cur+1, turn^1);
        int t = -nums[cur];
        for(int i=cur+1; (i<=cur+2)&&(i<n); i++){
            t -= nums[i];
            dp[cur][turn] = min(dp[cur][turn], t+dfs(i+1, turn^1));
        }
    }
    return dp[cur][turn];
}

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        nums = stoneValue;
        n = stoneValue.size();
        for(int i=0; i<50005; i++)
            for(int j=0; j<2; j++)
                visited[i][j] = 0;
        int ans = dfs(0,0);
        if(ans>0)
            return "Alice";
        else if(ans == 0)
            return "Tie";
        else  
            return "Bob";  
    }
};
```

预测一下石子游戏4， HAHAHA。
![e11117a1c461fabff52f8c2dd7b13b5.png](https://pic.leetcode-cn.com/8cbda3fb51af4583cd859801935a21a76468420778d133d84f918131eccf9e75-e11117a1c461fabff52f8c2dd7b13b5.png)

