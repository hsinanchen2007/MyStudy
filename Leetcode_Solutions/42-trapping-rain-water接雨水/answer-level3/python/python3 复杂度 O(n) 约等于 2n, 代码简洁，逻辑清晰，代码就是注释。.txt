### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        res = 0
        stack = []
        for i in range(1, len(height)):
            step = height[i] - height[i-1]
            if step < 0:
                stack.append((i-1, height[i-1]))
            if step > 0:
                base = height[i-1]
                while stack:
                    x, y = stack[-1]
                    if y > height[i]:
                        res += (i-1-x) * (height[i] - base)
                        break
                    else:
                        res += (i-1-x) * (y - base)
                        base += y - base
                        stack.pop()
        return res


```