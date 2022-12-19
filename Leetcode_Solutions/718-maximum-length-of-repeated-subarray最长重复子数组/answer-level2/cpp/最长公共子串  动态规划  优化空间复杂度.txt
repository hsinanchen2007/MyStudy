空间复杂度为O（mn）的动态规划的状态转移方程为：
*dp[i+1][j+1] = ( A[i+1] == B[j+1] ? (dp[i][j]+1) : 0 ); *
其中dp[i][j] 表示已字符A[i], B[j]为结尾的相同子串的最大长度。

这里可以对状态转移矩阵dp进行压缩，变为向量，但是由于dp[i+1][j+1] 的值与dp[i][j]有关， 
因此对于该向量的更新应该从后往前，此时状态转移矩阵为： 
*dp[j + 1] = ( A[i+1] == B[j+1] ? (dp[j]+1) : 0 );*

```
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) 
    {
        int length = 0;
        int sizeA = A.size();
        int sizeB = B.size();
        vector<int> matrix(sizeB + 1, 0);
        
        for(int i = 0; i < sizeA; i++)
        {
            for(int j = sizeB - 1; j >= 0; j--)
            {
                if(A[i] == B[j])
                {
                    matrix[j + 1] = matrix[j] + 1;
                    length = max(length, matrix[j + 1]);
                }
                else
                    matrix[j + 1] = 0;
            }
        }

        return length;
    }
};
```
