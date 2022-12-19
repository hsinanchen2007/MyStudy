```python
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # method: greedy

        # Time complexity: O(N)
        # Space complexity: O(N)

        # 原问题转换为 跳跃游戏II

        jump_arr = [0] * (n + 1)
        for i, step in enumerate(ranges):
            a, b = max(0, i - step), i + step
            jump_arr[a] = max(jump_arr[a], b)
        ans, max_dis, end = 0, 0, 0
        for i in range(n):
            max_dis = max(max_dis, jump_arr[i])
            if i == end:
                end = max_dis
                ans += 1
        return ans if end >= n else -1
```