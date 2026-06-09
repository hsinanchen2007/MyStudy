每一次都把当前元素队列右边
如果队列元素之和大于target, 左边元素出队
判断一下当前结果是不是等于target, 等于的话保存一下就可以了

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        from collections import deque
        if target == 1:
            return []
        res = []
        tmp = deque()
        cur_sum = 0
        for i in range(1, target // 2 + 2):
            cur_sum += i
            tmp.append(i)
            while cur_sum > target:
                cur_sum -= tmp.popleft()
            if cur_sum == target:
                res.append(list(tmp))
        return res
```