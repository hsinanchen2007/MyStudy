### 解题思路

算出每个坐标对应最高左右壁，减去自高即可。

### 代码

```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        n = len(height)
        left, right = [0] * n, [0] * n
        left[0], right[-1] = height[0], height[-1]
        for i in range(1, n):
            left[i] = max(height[i], left[i - 1])
        for i in reversed(range(n - 1)):
            right[i] = max(height[i], right[i + 1])
        return sum(min(l, r) - h for l, r, h in zip(left, right, height))
```