### 解题思路
1.分割子问题
设DP[i][j]矩阵表示以A[i-1]和B[j-1]为结尾元素的公共子数组的长度（注意：在最后形成的公共子数组结果中，最后一个元素必须为A[i-1]和B[j-1]，而不是说以A[i-1]和B[j-1]结尾的子数组再去寻找公共子数组）。
2.确定边界条件
DP[0][j]和DP[i][0]分别表示A和B为空串，显然结果都为0，以此作为边界条件。
3.分情况讨论递推公式：
当新增加的元素使两个子数组结尾元素相同时即A[i - 1] == B[j - 1]，DP[i][j] = DP[i-1][j-1]。
当新增加的元素使两个子数组结尾元素不同时，因为不可能存在结尾不同的公共子数组，所以DP[i][j]=0。


### 代码

```cpp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int Max = 0;
        int lenA = A.size();
        int lenB = B.size();
        vector<vector<int>> DP(lenA + 1, vector<int>(lenB + 1, 0));

        //设置边界条件
        for(int i = 0; i <= lenA; i++)
        {
            DP[i][0] = 0;
        }
        for(int j = 0; j <= lenB; j++)
        {
            DP[0][j] = 0;
        }

        for(int i = 1; i <= lenA; i++)
        {
            for(int j = 1; j <= lenB; j++)
            {
                if(A[i - 1] == B[j - 1])
                {
                    DP[i][j] = DP[i- 1][j - 1] + 1;
                }
                else
                {
                    DP[i][j] = 0;
                }
                Max = Max > DP[i][j] ? Max : DP[i][j];
            }
        }
        return Max;
    }
};
```