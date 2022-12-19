### 题解
维护queue队列，queue[0]始终记录着当前范围内的最大元素。

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        
        if k > len(nums) or len(nums)==0: 
            return []
        queue = collections.deque()

        for i in range(k):
            while queue and queue[-1] < nums[i]:
                queue.pop()
            queue.append(nums[i])

        left_idx = 0
        right_idx = k - 1
        ans = []
        ans.append(queue[0])

        # push the left item and pop the right in every round.
        while right_idx < len(nums) - 1:
            # judge the left
            if queue[0] == nums[left_idx]:
                queue.popleft()
            # judge the right
            left_idx += 1
            right_idx += 1
            # crucial part
            while queue and queue[-1] < nums[right_idx]:
                queue.pop()
            queue.append(nums[right_idx])
            ans.append(queue[0])
        
        return ans
```