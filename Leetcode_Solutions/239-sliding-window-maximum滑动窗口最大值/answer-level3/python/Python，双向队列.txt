```python
    def maxSlidingWindow(self, nums: list, k: int) -> list:
        q, res = [], []
        for i in range(len(nums)):
            if not q:  # 如果为空直接加入队列
                q.append(i)
            else:
                if i == q[0]+k:  # 如果队首的索引已位于滑动窗口之外，将其出队
                    q.pop(0)
                while q and nums[q[-1]] < nums[i]:  # 将小于当前值的队尾元素依次出队
                    q.pop()
                q.append(i)  # 将当前值加入队列
            res.append(nums[q[0]])  # 队首即最大值
        return res[k-1:]  # k-1前不是有效的滑动窗口
```
