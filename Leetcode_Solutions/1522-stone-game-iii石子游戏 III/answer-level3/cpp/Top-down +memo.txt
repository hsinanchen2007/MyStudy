### 解题思路
两个都是采取最优策略来博弈：要使A此刻最大，那么要在取1个、2个、3个石子三种策略中选择让B获益最小的策略，用
dp[i] 标识 面对第i个石子获取的最大利益，如何取得最大？枚举我方分别取3种策略时，哪一个让对方拿到最小，即
Min(dp[i+1], dp[i+2], dp[i+3])
此时 我方获取的利益 就是 总数-对方利益
典型的递归，有重叠计算，用memo 缓存中间结果。
### 代码

```cpp

class Solution {
public:
    
    vector<int> memo;
    vector<int> sum;
    int INF = 1e9;
    
    //自己最大，就是让对方最小 (最优策略)
    //top-down + memo
    string stoneGameIII(vector<int>& a) {
        //前缀和
        int N = a.size();
        sum.resize(N);
        memo.resize(N);
        for (int i = N-1; i >= 0; --i) {
            sum[i] = a[i] + (i == N-1 ? 0 : sum[i+1]);
            memo[i] = -INF;
        }
  
        dfs(0); //开始博弈
 
        int alice = memo[0], bob = sum[0] - alice;
        if (alice > bob) {
            return "Alice";
        } else if (alice < bob) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
    int dfs(int i) {
        if (i >= memo.size()) return 0;
        if (memo[i] != -INF) return memo[i];
        int res = -INF;
        for (int k = 0; k < 3; ++k) {
            res = max(res, sum[i] - dfs(i+k+1));
        }
        memo[i] = res;
        return res;
    }
};
```