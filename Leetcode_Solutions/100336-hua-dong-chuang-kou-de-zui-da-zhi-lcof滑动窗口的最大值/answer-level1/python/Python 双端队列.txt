```python
from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue, result = deque(), list()

        for i in range(len(nums)):
            if queue and queue[0] == i - k:
                # 如果最大值在当前滑动窗口之外，去掉它
                queue.popleft()
            
            while queue and nums[queue[-1]] < nums[i]:
                # 将小于当前元素的，全部从队列中推出
                queue.pop()

            queue.append(i)  # 将当前元素加入队列
            if i >= k - 1:
                result.append(nums[queue[0]])

        return result
```