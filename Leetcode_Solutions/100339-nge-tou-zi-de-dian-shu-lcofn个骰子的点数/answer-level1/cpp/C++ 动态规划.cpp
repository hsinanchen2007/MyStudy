### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<int>> dp(n+1,vector<int>(6*n+1));
        for(int i = 1;i <= 6;i++){
            dp[1][i] = 1;
        }
        for(int i = 2;i<=n;i++){
            for(int j = 1;j<=6;j++){
                for(int k = i-1; k <= 6*(i-1);k++)
                    dp[i][k+j]+=dp[i-1][k];
            }
        }
        double all = pow(6,n);
        vector<double> res;
        for(int i = n;i<=6*n;i++)
            res.emplace_back((double)dp[n][i]/all);
        return res;
    }
};
```