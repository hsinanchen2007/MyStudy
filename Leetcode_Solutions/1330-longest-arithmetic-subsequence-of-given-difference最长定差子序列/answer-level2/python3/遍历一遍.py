### 解题思路

暴力的解法遍历每个数，以这个数为开始，往后面不断的找相差为difference的数，时间复杂度是平方，肯定是会超时的。

这道题的标签是动态规划，那我们往这方面想，输入数组的长度从0开始，每次往后面添加一个数，如何在这个过程中，找到最长的子序列。
可以用一个dp数组，位置i表示以arr[i]结束的最长的等差子序列。
那么每次遍历到当前位置i,以及数num，，其实只要找到在它之前，离它最近的num-difference的位置j，dp[j]就表示以num-difference结尾的最长的等差子序列，dp[i]就等于1+d[j]。

在每次找j的过程中，如果用一个循环往前找的话，最坏的情况下，还是平方的复杂度。我们可以优化查找的过程，用一个map存储每个num最近的位置，那么每次查找的时间就可以从O(N)降到O(1).
最终算法的时间复杂的是O(N).
### 代码

```python3
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dp = [1]*len(arr)
        indices = {}
        for i, num in enumerate(arr):
            if num-difference in indices:
                dp[i] = 1 + dp[indices[num-difference]]
            indices[num] = i
        return max(dp)








```