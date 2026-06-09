### 解题思路
最开始想针对第一行的每个元素往下算到底，甚至想了一个剪枝的规则，但是在41个测试用例时还是超时了。下面是用动态规划方法做的，比较常规。

### 代码

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int size = A.size();        
        vector<vector<int>> dp(size, vector(size,10000));
        dp[0].assign(A[0].begin(), A[0].end());
        for(int i=1; i<size; i++){//i=1 start from the second row.
            for(int j=0; j<size; j++){
                int min;
                if(j-1>=0&&j+1<size){
                    min = dp[i-1][j-1]<dp[i-1][j]?dp[i-1][j-1]:dp[i-1][j];
                    min = min<dp[i-1][j+1]?min:dp[i-1][j+1];
                }
                else if(j-1>=0){
                    min = dp[i-1][j-1]<dp[i-1][j]?dp[i-1][j-1]:dp[i-1][j];
                }
                else if(j+1<size){
                    min = dp[i-1][j]<dp[i-1][j+1]?dp[i-1][j]:dp[i-1][j+1];
                }
                else{
                    min =dp[i-1][j];
                }
                dp[i][j] = A[i][j] + min;
            }
        }
        return *min_element(dp[size-1].begin(), dp[size-1].end());
    }
};
```