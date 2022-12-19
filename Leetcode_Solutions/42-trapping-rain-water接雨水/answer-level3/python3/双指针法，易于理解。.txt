### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        lens = len(height)
        point_left = 0
        point_right = lens - 1


        max_v = 0
        pre_v = 0
        if lens < 1:
            return max_v
        while point_left != point_right:
            # 左右指针不靠着
            # 从短的一端开始
            if height[point_left] > height[point_right]:
                # 移动右指针
                length_r = height[point_right]
                while length_r > height[point_right-1]:
                    pre_v += length_r - height[point_right - 1]
                    point_right -= 1
                else:
                    point_right -= 1
                max_v += pre_v
                pre_v = 0
            else:
                length_l = height[point_left]
                while length_l > height[point_left + 1]:
                    pre_v += length_l - height[point_left + 1]
                    point_left += 1
                else:
                    point_left = point_left + 1

                max_v += pre_v
                pre_v = 0
        return max_v
```