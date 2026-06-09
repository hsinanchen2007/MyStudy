在滑动的同时，我们要保证双端队列的第一个数为最大值
```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        from collections import deque
        d = deque()
        res = []
        for i in range(len(nums)):
            # 将比当前小的元素全部踢出去
            while d and nums[i] > nums[d[-1]]:
                d.pop()
            d.append(i)

            # 如果超过了滑动窗口的界限，将第一个元素踢出
            if i - k == d[0]:
                d.popleft()

            # 当deque的大小达到k的时候，开始记录最大值
            if i - k + 1 >= 0:
                res.append(nums[d[0]])
        return res
```
