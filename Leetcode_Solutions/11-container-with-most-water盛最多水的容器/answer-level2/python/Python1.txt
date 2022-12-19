### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxArea(self, height):
        area=0
        h=len(height)-1
        l=0
        while l<h:
            if (h-l)*min(height[h],height[l])>area:
                area=(h-l)*min(height[h],height[l])
            if height[l]<height[h]:
                l=l+1
            else:
                h=h-1
        return area
```