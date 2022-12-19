双指针方法：

执行用时 :52 ms, 在所有 Python3 提交中击败了90.64%的用户

内存消耗 :13.8 MB, 在所有 Python3 提交中击败了60.74%的用户
```python
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        l = 0
        r = n-1
        area = 0
        l_max_height = 0
        r_max_height = 0
        while l<r:
            if height[l] < height[r]:
                if height[l] < l_max_height:
                    area += l_max_height-height[l]
                else:
                    l_max_height = height[l]
                l += 1
            else:
                if height[r] < r_max_height:
                    area += r_max_height-height[r]
                else:
                    r_max_height = height[r]
                r -= 1
        return area

```
