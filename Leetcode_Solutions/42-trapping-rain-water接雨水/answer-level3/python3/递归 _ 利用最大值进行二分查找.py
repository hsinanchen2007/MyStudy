### 解题思路
考虑计算内容的补集，利用最大值进行二分查找，以求得需要减去的面积

### 代码

```python3
class Solution:

    def __init__(self):
        self.total = 0

    # 倒着找最大的那个值的序号
    def _rfind_list(self, l, v):
        for i in range(len(l) - 1, -1, -1):
            if l[i] == v:
                return i
        return -1

    # 对左边需要减去的值进行查找
    def _trap_left(self, height, right):
        if 0 >= right:
            return
        mid = self._rfind_list(height[:right], max(height[:right]))
        minus_res = right * (height[right] - height[mid])
        self.total -= minus_res
        self._trap_left(height, mid)

    # 对右边需要减去的值进行查找
    def _trap_right(self, height, left):
        if left >= len(height):
            return
        mid = left + height[left:].index(max(height[left:]))
        minus_res = (len(height) - left) * (height[left-1] - height[mid])
        self.total -= minus_res
        self._trap_right(height, mid+1)


    def trap(self, height: List[int]) -> int:
        if len(height) < 3:
            return 0

        # 总面积为宽为最大值，长为数组长度的矩形面积
        self.total = len(height) * max(height)

        mid = height.index(max(height))
        self._trap_left(height, mid)
        self._trap_right(height, mid + 1)

        # 减去柱子面积
        self.total -= sum(height)
        return self.total
```