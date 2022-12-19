### 解题思路
+ 数组内的高度值形成了一个个小坑，能接的雨水量的和就是这些小坑里的水的和。因此只要找到每一个小坑的左右边缘值就行了。
设置左右两组指针，每组各自又有高低两个指针，分别是`left_lo`,`left_hi`,`right_lo`,`right_hi`.


### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        N = len(height)
        left_lo, right_hi = 0, N - 1
        res = 0
        left_tmp, right_tmp = 0, 0  # 每个小坑的接水量
        while left_lo < N and height[left_lo] == 0: # 找到最左边的坑的左边缘
            left_lo += 1
        while right_hi >= 0 and height[right_hi] == 0:  # 找到最右边的坑的右边缘
            right_hi -= 1
        left_hi = left_lo + 1   # 开始找最左边的坑的右边缘
        right_lo = right_hi - 1 # 开始找最右边的坑的左边缘
        if left_hi > right_lo:  # 排除就俩数挨着的情况
            return res
        max_h = max(height)     # 最高的边缘，注意可能有很多个

        # 左边到最高：
        while height[left_lo] != max_h and left_hi < N:
            if height[left_hi] < height[left_lo]:
                left_tmp += height[left_lo] - height[left_hi]
                left_hi += 1
            else:
                left_lo = left_hi
                left_hi = left_lo + 1
                res += left_tmp
                left_tmp = 0
        # 右边到最高：
        while height[right_hi] != max_h and right_lo >= 0:
            if height[right_lo] < height[right_hi]:
                right_tmp += height[right_hi] - height[right_lo]
                right_lo -= 1
            else:
                right_hi = right_lo
                right_lo = right_hi - 1
                res += right_tmp
                right_tmp = 0
        # 可能有多个最高，最高中间还有坑
        while left_lo < right_hi:
            if height[left_hi] < height[left_lo]:
                left_tmp += height[left_lo] - height[left_hi]
                left_hi += 1
            else:
                left_lo = left_hi
                left_hi = left_lo + 1
                res += left_tmp
                left_tmp = 0
        return res
```