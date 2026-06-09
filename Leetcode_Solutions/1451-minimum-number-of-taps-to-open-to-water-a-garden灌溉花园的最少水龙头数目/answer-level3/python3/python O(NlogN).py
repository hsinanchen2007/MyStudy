```python
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # Time complexity: O(NlogN)
        # Space complexity: O(N)
        ranges = [[i - r, i + r] for i, r in enumerate(ranges)]
        ranges.sort(key = lambda x: x[0]) # O(NlogN)
        ranges.append((n, n))
        left, right = 0, 0
        ans = 0
        for i, (a, b) in enumerate(ranges): # O(N)
            if a > left:
                left = right
                ans += 1
            if a <= left: right = max(right, b)
        return ans if right >= n else -1




```