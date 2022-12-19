### 解题思路
此处撰写解题思路

### 代码

```python
from collections import deque
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        n = len(nums)
        if n * k == 0:
            return []
        if k == 1:
            return nums
        def clean_deque(i):
            #清除在窗口范围内的索引
            if deq and deq[0] == i - k:
                deq.popleft()
            while deq and nums[i] > nums[deq[-1]]:
                deq.pop()
        deq = deque()
        out = []
        maxIdx = 0
        for i in range(k):
            clean_deque(i)
            deq.append(i)
            if nums[i] > nums[maxIdx]:
                maxIdx = i
        out.append(nums[maxIdx])
        for i in range(k,n):
            clean_deque(i)
            deq.append(i)
            out.append(nums[deq[0]])
        return out
             
```