### 解题思路
时间复杂度O(n)

### 代码

```python3
class Solution:
    def trap(self, height):
        if len(height) < 3: return 0
        a = 0
        b = len(height) -1
        count = 0
        hsave = 0
        while a < b:
            h = min(height[a],height[b])
            hsave = max(h,hsave)
            if height[a]>height[b]:
                b = b-1
                if height[b]< hsave:
                    count = count - height[b] + hsave
            else:
                a = a+ 1
                if height[a]< hsave:
                    count = count - height[a] + hsave


        return count
```