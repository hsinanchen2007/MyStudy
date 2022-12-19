### 解题思路
双指针法，其实就是将问题简化为一个双指针遍历问题，容积取决于两个之间较小的height，所以遍历同时记录最大值

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        left_max, right_max = 0, len(height) - 1
        while left_max < right_max:
            if height[left_max] < height[right_max]:
                max_area = max(max_area, height[left_max] * (right_max - left_max))
                left_max += 1
            else:
                max_area = max(max_area, height[right_max] * (right_max - left_max))
                right_max -= 1
        return max_area
```