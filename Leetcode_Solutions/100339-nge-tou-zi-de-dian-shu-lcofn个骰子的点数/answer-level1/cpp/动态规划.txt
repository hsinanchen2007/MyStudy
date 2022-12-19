![image.png](https://pic.leetcode-cn.com/93791b375d6e6a20a3b485e381d349614bb0303657d067a7ecb79141cc30ddb0-image.png)

### 解题思路
动态规划思路：假设当前只有1个骰子，那么结果为1~6的情况都只有一种；此使再拿出第2骰子，第2个骰子的结果为1~6也都只有一种，那么这2个骰子的总结果为2的情况就有1种，为3的请情况有2种(12和21)，为4有3种(13,31,22)...以此类推，那么可以得到递归公式
dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+...+dp[i-1][j-6]     (dp[i][j]表示有i个骰子时结果为j有多少种情况)**注意边界考虑边界**
最后计算一共有**多少种情况(sum)**，返回几率为**当前情况数除以总和(dp[i][j]/sum)**
下述代码中将dp[i][0]设置为总和
### 代码

```cpp
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<int>>dp;
        dp.emplace_back(vector<int>());
        for(int i=1;i<=n;i++){
            dp.emplace_back(vector<int>(6*n+1,0));
            if(i==1){
                dp[i][0]=6;
                for(int j=1;j<=6;j++)
                    dp[i][j]=1;
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=i;j<dp[i].size();j++){
                for(int k=1;k<=6;k++){
                    if(j-k<i-1)
                        break;
                    dp[i][j]+=dp[i-1][j-k];
                }
                dp[i][0]+=dp[i][j];
            }
        }
        vector<double>res;
        int sum=dp.back().front();
        for(int i=1;i<dp.back().size();i++)
            if(dp.back()[i]>0)
                res.emplace_back((double)dp.back()[i]/sum);
        return res;
    }
};
```