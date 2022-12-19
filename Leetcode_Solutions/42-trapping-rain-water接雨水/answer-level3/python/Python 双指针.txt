对于当前高度, 可以盛的雨水为他左边的最高值和右边的最高值中较小的一个, 减去它自身的高度
```
value = min(max_left, max_right) - cur_height
```
所以构造两个指针, 另外用两个值保存左指针左边的最大值`max_left`, 和右指针右边的最大值`max_right`.
如果`max_left < max_right`,对于左指针指向的位置,他左边的最大值就是`max_left`, 右边的最大值肯定不小于`max_right`,所以 `value = max_left - cur_height`. 然后移动左指针
反之, 对于右指针指向的位置, 他右边的最大值就是`max_right`, 左边的最大值肯定不小于`max_left`, 所以`value = max_right - cur_height`, 然后移动右指针即可.

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        res = 0
        if n < 3:
            return res
        left = 1
        right = n - 2
        max_left = height[0]
        max_right = height[n - 1]
        while left <= right:
            max_left = max(max_left, height[left])
            max_right = max(max_right, height[right])
            if max_left < max_right:
                if height[left] < max_left:
                    res += max_left - height[left]
                left += 1
            else:
                if height[right] < max_right:
                    res += max_right - height[right]
                right -= 1
        return res
```

