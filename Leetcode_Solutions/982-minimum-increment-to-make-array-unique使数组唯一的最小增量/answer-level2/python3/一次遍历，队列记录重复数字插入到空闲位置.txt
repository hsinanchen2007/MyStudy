### 解题思路
。 排序后找到重复的数字加入到待处理的队列中去， 找到可以插入的空位时，将队列中存在的数字取出放到空位，直到数据处理完成； 特别注意在数组最后添加重复数字的场景；

### 代码

```python3

from collections import deque


class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if len(A) <= 1:
            return 0
        A.sort()
        q = deque()
        move = 0
        for i in range(1, len(A)):
            if A[i] == A[i - 1]:
                q.append(A[i])
            elif A[i] - A[i - 1] > 1:
                start = A[i - 1] + 1
                while q and start < A[i]:
                    curr = q.popleft()
                    move += start - curr
                    start += 1
        # 处理最后添加的场景；
        start = A[-1] + 1
        while q:
            curr = q.popleft()
            move += start - curr
            start += 1
        return move


```

# 运行情况
```
执行用时 :360 ms, 在所有 Python3 提交中击败了88.51%的用户
内存消耗 :18.7 MB, 在所有 Python3 提交中击败了15.38%的用户
```