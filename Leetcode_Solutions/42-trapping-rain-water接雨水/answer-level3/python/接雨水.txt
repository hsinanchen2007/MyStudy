### 解题思路

找到数组中从下标 i 到最左端最高的条形块高度 \text{left_max}。
找到数组中从下标 i 到最右端最高的条形块高度 \text{right_max}。
扫描数组 \text{height}并更新答案：
累加 \min(\text{max_left}[i],\text{max_right}[i]) - \text{height}[i]到 总面积上
### 代码

```python
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_left = [0]         
        for h in height:             
            max_left.append(max(max_left[-1], h))
        max_right = 0    
        res = 0
        n = len(height)
        for i in range(n):
            max_right = max(max_right, height[n-i-1])
            
            res += min(max_right, max_left[n-i]) - height[n-i-1]
        return res
```