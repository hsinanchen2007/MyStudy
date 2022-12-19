### 解题思路
执行用时 :
108 ms
, 在所有 Python 提交中击败了
100.00%
的用户
内存消耗 :
14.5 MB
, 在所有 Python 提交中击败了
100.00%
的用户

因为这个数组里面肯定存在相邻是相等的数字 设dp[i]是以i为结尾的最长个数 
如果nums[i] == nums[i-1] 则nums[i]最长是1 
如果满足条件则dp[i]=dp[i-1]+1
如果不相等又不满足条件则dp[i]=2

### 代码

```python
class Solution(object):
    def maxTurbulenceSize(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        size = len(A)
        if size == 1:
            return 1
        dp = [0]*size
        dp[0] = 1
        dp[1] = 2 if A[0] != A[1] else 1
        for i in range(2,size):
            if A[i] == A[i-1]:
                dp[i] = 1
                continue
            if A[i] > A[i-1] and A[i-1] < A[i-2]:
                dp[i] = dp[i-1] + 1
                continue
            if A[i] < A[i-1] and A[i-1] > A[i-2]:
                dp[i] = dp[i-1] + 1
                continue
            else:
                dp[i] = 2
        return max(dp)
            




```