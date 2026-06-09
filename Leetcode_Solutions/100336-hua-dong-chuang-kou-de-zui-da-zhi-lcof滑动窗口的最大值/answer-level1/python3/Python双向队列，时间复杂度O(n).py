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
        if k * len(nums) == 0:
            return []

        if k == 1:
            return nums

        # 双向队列，队头存放当前窗口最大值的下标
        deq = []
        res = []

        for i in range(len(nums)):
            # 清理队列
            # (1)如果队头不在窗口内，弹出
            if deq and deq[0] == i - k:
                deq.pop(0)

            # 清理队列
            # (2)如果队尾比当前元素小，弹出
            while deq and nums[deq[-1]] < nums[i]:
                deq.pop()

            deq.append(i)
            if i >= k - 1:
                res.append(nums[deq[0]])

        return res

```