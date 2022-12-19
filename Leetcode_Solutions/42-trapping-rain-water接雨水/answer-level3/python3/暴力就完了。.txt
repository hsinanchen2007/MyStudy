### 解题思路
每个柱子接的水等于左边最大和右边最大的最小值减去柱子高度。

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        res = []
        for i in range(1, len(height) - 1):
            res.append(min(max(height[0:i + 1]), max(height[i:])) - height[i])
        return sum(res)
```