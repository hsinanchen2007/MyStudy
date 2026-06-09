### 解题思路
![image.png](https://pic.leetcode-cn.com/3df39222ac3977e7ed04a1cd5b50f2adc584fd2eea8a9e356138707a2b8258cc-image.png)

### 代码

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(); if(m==0) return 0;
        int n = matrix[0].size(); if(n==0) return 0;

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int max_num = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0) dp[i][j] = matrix[i][j]-'0';
                else{
                    if(matrix[i][j]=='1'){
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
                        
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                max_num = max(max_num,dp[i][j]);
            }
        }
        return max_num*max_num;
    }
};
```