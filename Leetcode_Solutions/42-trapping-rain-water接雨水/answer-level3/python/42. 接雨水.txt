### 解题思路
遍历每一列，然后分别求出这一列两边最高的墙`left_max, right_max`；
找出较矮的一端`min（left_max, right_max）`，和当前列的高度`height[i]`比较；
如果较矮一端的高度也高于当前列，则该列加上`min（left_max, right_max）-height[i]`体积的水；

### 代码
```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        # 基础方法，双指针
        res = 0
        for i in range(1, len(height)-1):  # 最左与最右的位置无需考虑，不可能接到水
            max_left = 0
            for j in range(0, i):
                if height[j] > max_left:
                    max_left = height[j]
            max_right = 0
            for j in range(i+1, len(height)):
                if height[j] > max_right:
                    max_right = height[j]
            if max_left > height[i] and max_right > height[i]:
                res += min(max_right, max_left)-height[i]
        return res

        # 优化时间复杂度，用数组存储max_left和max_right的值，避免每次循环找最大值
        res = 0
        max_left = [0 for i in range(len(height))]
        for i in range(1, len(height)-1):
            max_left[i] = max(max_left[i-1], height[i-1])

        max_right = [0 for i in range(len(height))]
        for i in range(len(height)-2, 0, -1):
            max_right[i] = max(max_right[i+1], height[i+1])
            
        for i in range(1, len(height)-1):
            if height[i] < max_left[i] and height[i] < max_right[i]:
                res += min(max_right[i], max_left[i])-height[i]
        return res
```