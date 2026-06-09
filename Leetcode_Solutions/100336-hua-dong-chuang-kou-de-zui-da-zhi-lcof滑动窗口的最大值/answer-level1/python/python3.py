### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        deque = collections.deque() #存储 nums 索引
        res = []
        for i in range(len(nums)):
            if deque and i - deque[0] > k -1:  #队列元素控制在 k 内
                deque.popleft()
            while deque and nums[deque[-1]] < nums[i]:  #维护一个单调递减队列
                deque.pop()
            deque.append(i)
            if i >= k - 1:
                res.append(nums[deque[0]])
        return res

```