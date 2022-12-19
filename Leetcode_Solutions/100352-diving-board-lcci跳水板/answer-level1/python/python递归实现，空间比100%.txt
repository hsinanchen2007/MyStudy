```python
class Solution(object):
    def __init__(self):
        self.ans = []

    def divingBoard(self, shorter, longer, k):
        """
        :type shorter: int
        :type longer: int
        :type k: int
        :rtype: List[int]
        """
        if k == 0:
            return []
        if shorter == longer:
            return [shorter * k]

        self.rec(shorter, longer, 0, k, k)
        return self.ans

    def rec(self, shorter, longer, i, h, k):
        if h < 0: return

        self.ans.append(i*longer + (k-i)*shorter)

        self.rec(shorter, longer, i+1, k-i-1, k)
```