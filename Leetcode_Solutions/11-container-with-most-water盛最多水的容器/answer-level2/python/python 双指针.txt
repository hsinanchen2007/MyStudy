### 解题思路
定义双指针i，j比较height[i]和height[j]的大小，然后一次往中间靠，取得最大值

### 代码

```python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i = 0
        j = len(height) - 1
        max_Area = (j - i) * min(height[i], height[j])
        while i < j:
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
            max_Area = max(max_Area, (j - i) * min(height[i], height[j]))
        return max_Area
```