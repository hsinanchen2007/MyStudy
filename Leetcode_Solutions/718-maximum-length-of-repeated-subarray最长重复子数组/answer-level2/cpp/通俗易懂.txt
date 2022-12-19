可以借助**最长重复子串**的解题思路来解决这道问题。

还是动态规划的方法，面对数组A,B，使用一个二维数组dp来记录遍历时的状态。通过，dp[i, j] 表示**A数组的第i个数与B数组的第j个数对应的最长重复子数组的长**，通过分析，得到两种情况：

 - A[i] == B[j] , **dp[i][j] = dp[i][j-1] + 1**；	maxLen = max(dp[i][j], maxLen);
 - A[i] != B[j], j++(j < B.size) ;  i++(i < A.size)；

例如示例所给出的，通过dp数组记录的为：
```
0 0 1 2 3
0 1 0 1 2
1 0 0 0 1
0 0 0 0 0
0 0 0 0 0
```


```
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(B.empty()){
            return 0;
        }
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        int maxLength = 0;
        for(int i = 1; i <= A.size(); i++){
            for(int j = 1; j <= B.size(); j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }

        return maxLength;
    }
};
```
