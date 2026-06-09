```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        deque = [];result = [] # deque也可以用collection里的双端队列实现
        for i in range(0, len(nums)):
            while deque and nums[i]>nums[deque[-1]]: # 只存有可能成为最大值的数字的index进deque
                deque.pop()
            deque.append(i)
            while i-deque[0]>k-1: # 如果相距超过窗口k长度则弃掉
                deque.pop(0)
            if i >= k-1:
                result.append(nums[deque[0]]) # 这过程中始终保持deque[0]为最大值的index
        return result
```
