### 解题思路
面积关系rain=whole-body-air

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        top = max(height)
        body = sum(height)
        n = len(height)
        whole = n * top
        acc = 0

        # method1
        t = 0
        for val in height:
            if val == top:
                break
            t = max(t, val)
            acc += top -t
        t = 0
        for val in height[::-1]:
            if val == top:
                break
            t = max(t, val)
            acc += top -t

        # # method2
        # i = 0
        # t = 0
        # while height[i] != top:
        #     t = max(t, height[i])
        #     acc += top - t 
        #     i += 1
        # i = n-1
        # t = 0
        # while height[i] != top:
        #     t = max(t, height[i])
        #     acc += top - t 
        #     i -= 1
        
        return whole - body - acc
```