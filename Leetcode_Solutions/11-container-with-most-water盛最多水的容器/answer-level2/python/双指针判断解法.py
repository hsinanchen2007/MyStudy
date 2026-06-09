### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        first = 0
        last = len(height)-1
        area = (last-first)*min(height[first],height[last])
        for (i,v) in enumerate(height):
            if first==last:
                break
            if height[first]>height[last]:
                last = last-1
            elif height[first]==height[last]:
                if height[first+1]>height[last-1]:
                    first = first+1
                else:
                    last = last-1
            else:
                first = first+1
            area = max(area, (last-first)*min(height[first],height[last]))
        return area
```