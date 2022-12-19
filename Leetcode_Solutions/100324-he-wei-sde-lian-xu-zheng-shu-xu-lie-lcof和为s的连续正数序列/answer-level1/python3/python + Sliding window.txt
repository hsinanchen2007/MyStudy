```python
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        # sliding window
        l, r = 1, 1
        curSum = 0
        res = []
        curSeq = collections.deque()
        # target = 9
        # 2, 3, 4, > 9

        while r < target:
            curSum += r
            while curSum > target:
                curSum -= l
                curSeq.popleft()
                l += 1
            curSeq.append(r)
            if curSum == target:
                res.append(list(curSeq))
            r += 1
        return res
```