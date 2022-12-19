```
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        count, new = 0, sorted(heights)
        for i, j in zip(heights, new):
            if (i - j) != 0:
                count += 1
        return count
```
这可能是leetcode上最简单的一道题了！