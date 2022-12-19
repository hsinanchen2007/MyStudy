### 解题思路
先按照len*max（height）计算出整个区域的面积，再减去拦不住会流失的水，再减去柱子占的面积

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if height == [] :
            return 0
        res = len(height) * max(height)
        key = 0
        for i in range(len(height)):
            
            if(height[i] != max(height)):

                if height[i] > key:
                    key = height[i]
                res -= (max(height) - key)

            else:
                break
        key = 0
        for i in range(len(height)-1,-1,-1):
            
            if(height[i] != max(height)):

                if height[i] > key:
                    key = height[i]
                res -= (max(height) - key)

            else:
                break
        return res - sum(height)
```