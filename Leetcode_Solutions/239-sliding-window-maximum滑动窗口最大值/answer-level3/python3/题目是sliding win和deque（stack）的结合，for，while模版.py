### 解题思路
题目是sliding win和deque（stack）的结合，for，while模版
### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:

        deq = collections.deque()
        res = []

        # 套路是一个for遍历全部值
        for idx,v in enumerate(nums):
            # 另一个有条件的连续去掉stack的值，如果这个值明显比最后一个值大
            while deq and v>nums[deq[-1]]:
                deq.pop()
            # 存的是idx
            deq.append(idx)
            # cal the idx diff, 当前id-diff
            # 如果是stack里面存的idx的话说明超出了，则需要弹出最左边的那个
            if deq[0] == idx - k:
                deq.popleft()
            # first window start with k-1
            if idx >= k-1:
                res.append(nums[deq[0]])

        return res     

```