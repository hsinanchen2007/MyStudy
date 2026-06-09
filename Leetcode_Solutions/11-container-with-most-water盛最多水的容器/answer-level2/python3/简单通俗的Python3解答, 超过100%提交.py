### 解题思路
长方形面积 S = (j - i) * h
双指针从左右开始往内收, 算出S后, 要想办法尽可能扩大S.
已知 h = min(h[j], h[i]),
假设h[j] > h[i], 那么往内收的时候, 到底应该收较长的j还是收较短i???

从计算面积S = (j - i) * h公式出发. (j - i)肯定是要变小的. 那么如果只移动j, h就还是等于短高h[i]的值, 这只会让S变小.
所以, 只能移动较短的i, 使得高度h有可能变大.

### 代码

```python3
class Solution:
    def calc_area(self, a, b, alist):
        return abs(a - b) * min(alist[a], alist[b])

    def maxArea(self, height: List[int]) -> int:
        # (i2 - i1) * min(a[i2], a[i1]) 需要最大
        len_h = len(height)
        max_value = 0
        i = 0
        j = len_h - 1
        while i < j:
            area = self.calc_area(i, j, height)
            max_value = max(max_value, area)
            # 那条高比较短就移动哪个指针
            if height[i] <= height[j]:
                i += 1
            else:
                j -= 1
        
        return max_value
```