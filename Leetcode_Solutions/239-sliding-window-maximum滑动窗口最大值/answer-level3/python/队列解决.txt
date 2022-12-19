### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        queue = collections.deque()
        ans = []

        for i in xrange(len(nums)):
            if i >= k:
                if nums[i-k] == queue[0]:
                    queue.popleft()

            while queue and nums[i] > queue[-1]:
                queue.pop()
            queue.append(nums[i])

            i >= k-1 and ans.append(queue[0])

        return ans

```