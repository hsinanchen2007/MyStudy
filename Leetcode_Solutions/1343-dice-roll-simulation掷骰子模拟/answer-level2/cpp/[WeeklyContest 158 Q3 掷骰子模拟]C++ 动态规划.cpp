[[WeeklyContest 158 Q1 分割平衡字符串]C++](https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/solution/weeklycontest-158-q1-fen-ge-ping-heng-zi-fu-chuan-/)
[[WeeklyContest 158 Q2 可以攻击国王的皇后]C++ 迭代](https://leetcode-cn.com/problems/queens-that-can-attack-the-king/solution/weeklycontest-158-q2-ke-yi-gong-ji-guo-wang-de-hua/)
[[WeeklyContest 158 Q3 掷骰子模拟]C++ 动态规划](https://leetcode-cn.com/problems/dice-roll-simulation/solution/weeklycontest-158-q3-zhi-tou-zi-mo-ni-c-dong-tai-g/)
[[WeeklyContest 158 Q4 最大相等频率]C++ 分类讨论](https://leetcode-cn.com/problems/maximum-equal-frequency/solution/weeklycontest-158-q4-zui-da-xiang-deng-pin-lu-c-fe/)

思路：
```
动态规划。
状态描述：dp[i][j][k] 以k个j结尾，并已经投了i次的合法情况数。
递推关系：
    当k==1，表示最后一个字符j仅出现了一次，因此，前一个字符不与j相同即为合法情况，加起来即可。下面以j==1为例，
    k == 1:
    dp[i][1][1] = (dp[i-1][2][1]+dp[i-1][2][2]+...+dp[i-1][2][15])+(dp[i-1][3][1]+dp[i-1][3][2]+...+dp[i-1][3][15])
                    ...+(dp[i-1][6][1]+dp[i-1][6][2]+...+dp[i-1][6][15])
    当k>1，则前面那个字符需要出现k-1次。
    k > 1:
    dp[i][1][k] = dp[i-1][1][k-1]
初始化：第一次投。dp[1][1][1] = 1; dp[1][2][1] = 1; dp[1][3][1] = 1; dp[1][4][1] = 1; dp[1][5][1] = 1; dp[1][6][1] = 1;
```

```
class Solution {
    typedef long long LL;
    int MOD = 1e9+7;
    int dp[5050][7][16];    //dp[i][j][k] represent num j appear k times and i chances used;
    
    void add(int& a, int b){
        a += b;
        if(a >= MOD) a -= MOD;
    }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, 0, sizeof(dp));
        dp[1][1][1] = 1; dp[1][2][1] = 1; dp[1][3][1] = 1; dp[1][4][1] = 1; dp[1][5][1] = 1; dp[1][6][1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= 6; j++){
                for(int k = 1; k <= rollMax[j-1] && k <= i; k++){
                    // k==1
                    if(k == 1){
                        for(int m = 1; m <= 6; m++){
                            if(m != j){
                                for(int s = 1; s <= rollMax[m-1] && s <= i-1; s++){
                                    add(dp[i][j][k], dp[i-1][m][s]);
                                    
                                }
                            }
                        }
                    }
                    // k>1
                    else{
                        dp[i][j][k] = dp[i-1][j][k-1];
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= 6; i++){
            for(int j = 1; j < 16; j++){
                add(ans, dp[n][i][j]);
            }
        }
        return ans;
    }
};

```