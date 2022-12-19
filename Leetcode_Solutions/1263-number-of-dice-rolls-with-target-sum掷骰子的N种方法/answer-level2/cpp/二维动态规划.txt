### 解题思路
建立二维动态规划矩阵，两个维度分别为骰子个数d，以及目标值target。初始化d等于1时的那一行，然后逐行计算，与上一行相比，当前行只多了一个骰子的值，因此可以将上一行对应的一些值（即少一个骰子的所有情况）累加来得到当前值。

### 代码

```cpp
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
            vector<vector<int>> dp(d+1,vector<int>(target+1,0));
            for(int i=1;i<=min(f,target);i++){
                dp[1][i]=1;
            }
            for(int i=2;i<=d;i++){
                for(int j=i;j<=target;j++){
                    for(int k=j-1;k>0&&k>=j-f;k--){
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
                    }
                }
            }
            return dp[d][target];
    }
};
```