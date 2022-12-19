### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :9.6 MB, 在所有 C++ 提交中击败了8.31%的用户

dp[i][j]表示以i和j结尾（i > j）的等差数列的总数

dp[i][i - 1] = dp[i - 1][i - 2] + 1(当A[i][i - 1] == A[i - 1][i - 2]，+1是表示仅使用i,i - 1,i - 2构成等差数列这种情况)
dp[i][i - 1] = 0(当A[i][i - 1] != A[i - 1][i - 2]，不存在有效的等差数列)
时间复杂度O(n)，空间复杂度O(1)

### 代码

```cpp
class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {   
        int n = A.size();
        int dp = 0;
        int ans = 0;

        for(int i = 2;i < n;i++)
        {
            if((A[i - 1] - A[i - 2]) == (A[i] - A[i - 1]))
            {
                dp++;
            }
            else
            {
                ans += ((dp + 1) * dp) >> 1;//求和优化，n(n+1)/2表示1+2+...+n的和，下同
                dp = 0;
            }
        }

        return ans + (((dp + 1) * dp) >> 1);
    }
};
```