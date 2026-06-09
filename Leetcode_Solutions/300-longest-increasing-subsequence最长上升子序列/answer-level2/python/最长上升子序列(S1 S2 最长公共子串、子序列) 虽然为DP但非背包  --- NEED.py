### 解题思路
1. [最长上升子序列 (LIS) 详解+例题模板 (全)](https://blog.csdn.net/lxt_Lucia/article/details/81206439)
    - 最长公共子序列-**状态定义**：*d(i)就是以A[i]结尾的最长公共子序列（含结尾元素）*
    - **状态转移：若A[i] > A[j] (0<j<i>), A[i] = max(A[j]) + 1 ; 当A[i]之前没有比A[i]更小的数时，d(i)=1**
    - 初始化：dp = [0 for j in range(nsize)]  and dp[0] = 1
    - 这个DP算法的时间复杂度为〇(n²)
    - **贪心 + 二分查找：**

2. [动态规划经典例题——最长公共子序列和最长公共子串（python）](https://blog.csdn.net/ggdhs/article/details/90713154)
    - **公共子串 -状态定义**：dp[i][j] 表示以sa[i] 和sb[j] *为结尾的公共子串(子串含结尾元素) ，dp[size_a][size_b]非最终结果*
    - **公共子串 -状态转移**：若sa[i] == sb[j], 则 dp[i][j] = dp[i-1][j-1] + 1； 否则 dp[i][j] = 0，并记录max_值
    - 公共子串-初始化：dp = [[0 for i in range(len1+1)] for j in range(len2+1)]
    - **若求公共子串：记录最大max_时，i和j的值，可能多个**

    - **公共子序列-状态定义**：dp[i][j] *表示sa的前i个元素和sb的前j个元素的公共子序列，从定义可知，dp[size_a][size_b]即为最终结果*
    - **公共子串-状态转移**：若sa[i] == sb[j],则dp[i][j] = dp[i-1][j-1] +1；否则 dp[i][j] = max( dp[i-1][j], dp[i][j-1]) )
    - 公共子序列-初始化：同子串 dp = [[0 for i in range(len1+1)] for j in range(len2+1)]
    - **若求公共子序列**：需要从dp[size_a][size_b] 逆势回溯找即可
        - 通过递推公式，可以看出，dp[i][j]的值来源于dp[i-1][j-]+1或者是dp[i-1][j]和dp[i][j-1]的较大值（可能相等）
        - 因此，若s[i] == s[j] （即 dp[i][j] == dp[i-1][j-]+1），则直接对角线；
        - 若s[i] != s[j] 则回退到 dp[i-1][j]和dp[i][j-1]的较大者。（若是dp[i-1][j]==dp[i][j-1]，则选定左侧或上侧，之后一直是这个方向。）

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        nsize = len(nums)

        if nsize < 2:
            return nsize
        
        dp = [0 for j in range(nsize)]
        dp[0] = 1

        i = 1
        while i < nsize:
            j = i-1
            while j >= 0:
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j])
                j -= 1
            dp[i] += 1
            i += 1

        return max(dp)

```