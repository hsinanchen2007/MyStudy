一次遍历
```
class Solution:
    def candy(self, ratings) -> int:
        n = len(ratings)
        left = [1] * n
        right = left.copy()
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                left[i] = left[i - 1] + 1
            if ratings[~i] > ratings[~i + 1]:
                right[~i] = right[~i + 1] + 1
        return sum([max(l, r) for l, r in zip(left, right)])
```
