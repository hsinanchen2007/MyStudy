### 解题思路
思路就是保证最左边的板子是第二高的，最右边板子是最高的（指针往后挪，直到碰到比最左高的板子，计算面积）。这种情况的面积就是sum(height[start] - x for x in height[start:end])。
循环终止时，说明start挪到了最高点，把剩下的数组翻转过来，按照上面的方法求面积即可。

### 代码

```python
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        if n <= 2: 
            return 0
        
        area = 0
        start = 0     
        end = 1
        while end < n:
            while end < n and height[end] < height[start]:
                end += 1
            
            if end < n:
                minimum = height[start]
                area += sum(minimum - x for x in height[start:end])
                start = end
                end = start + 1

        area += self.trap(height[start:][::-1])
        return area


```