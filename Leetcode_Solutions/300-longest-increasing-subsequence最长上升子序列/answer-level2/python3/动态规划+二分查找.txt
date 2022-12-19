动态规划是比较容易想到的方法，这样复杂度是O(n^2)。
用一个数组记录以当前位置结尾的最长上升子序列长度，对于每个位置i，找到前面比它小的长度最大的j，dp[i] = dp[j] + 1。
可以把前面的结果存在一个队列中，并保持队列单调递增；对于每个位置i，如果前面的某一个位置比它数值更大且长度更小，则可以将其去掉；那么剩下的要么比它数值小，要么比它长度大，可以把j+1位置的替换为(nums[i], dp[i])。
因为队列是单调的，在查找j时，可以使用二分查找，这样复杂度变成O(nlogn)。

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        dp, max_dp = 0, 0
        max_length = 0
        queue = collections.deque()
        for i in range(n):
            if i == 0:
                dp = 1
                queue.append((nums[i], 1))
            else:
                j = self.binsearch(queue, nums[i])
                if j == -1:
                    dp = 1
                else:
                    dp = queue[j][1] + 1
                while len(queue) > 0 and queue[-1][0] > nums[i] and queue[-1][1] <= dp:
                    queue.pop()
                if len(queue) > 0 and queue[-1][0] > nums[i]:
                    queue[j + 1] = (nums[i], dp)
                else:
                    queue.append((nums[i], dp))
            max_dp = max(max_dp, dp)
        return max_dp

    def binsearch(self, queue, val):
        l, r = 0, len(queue) - 1
        while l < r - 1:
            m = (l + r) // 2
            if queue[m][0] >= val:
                r = m - 1
            else:
                l = m
        if queue[r][0] < val:
            return r 
        elif queue[l][0] < val:
            return l 
        else:
            return -1
```
