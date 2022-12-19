### 解题思路
可以认为两边是两块挡板，不断的更换两边的挡板，直到挡板之间完全没有空隙，则停止移动挡板。其实类似于求一个一维数组中最大值的问题。

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max = 0
        low = 0
        high = len(height)-1
        if low == high:
            return max
        for i in range(len(height)):
            # 如果左侧低，则面积用左侧的高度 并且向右移动左边的边界
            if height[low] < height[high]:
                container = height[low] * (high - low)
                low += 1
            # 如果右侧低，则面积用右侧的高度 并且向左移动右边的边界
            else:
                container = height[high] * (high - low)
                high -= 1
            if container > max:
                max = container
        return max
```