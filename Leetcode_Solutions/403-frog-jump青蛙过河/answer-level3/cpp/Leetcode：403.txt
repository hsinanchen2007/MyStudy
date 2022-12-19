### 解题思路
首先设石头的个数为n 步长jump最长也就是 n - 1
状态表示： dp[x][z] 表示跳到第x块石头上所用的步长为z dp[][z]仅与dp[][z - 1] dp[][z] dp[][z + 1]有关
状态转移：dp[x][z] = dp[y][z - 1] || dp[y][z] || dp[y][z + 1] 其中 y∈[0, x - 1]
边界条件： 设 x 和 y 之间的距离为 dis = stones[x] - stones[y]  如果dis >= n(n为石头的个数) 则从j -> i的转移不成立
转移顺序：从x = 0 ==> x = n - 1

### 代码

```cpp
#define ll long long
const int MAXN = 1050;
ll dp[MAXN][MAXN];
class Solution {
public:
    bool canCross(vector<int>& stones) {
        ll n = stones.size();
        if(stones[1] - stones[0] > 1) return false;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1; dp[1][1] = 1;
        for(ll i = 2; i < n; i++){
            for(ll j = 0; j <= i - 1; j++){
                ll dis = stones[i] - stones[j];
                if(dis >= MAXN - 1) continue; 
                dp[i][dis] = dp[j][dis - 1] + dp[j][dis] + dp[j][dis + 1];
                if(dp[i][dis] > 1) dp[i][dis] = 1;
            }
        }
        for(ll k = 0; k <= n; k++){
            if(dp[n - 1][k] >= 1) return true;
        }
        return false;
    }
};
```