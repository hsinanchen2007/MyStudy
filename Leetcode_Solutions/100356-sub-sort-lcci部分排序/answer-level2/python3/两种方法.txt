### 方法1 (O(N)): 两个方向遍历
1. 从左向右找小于当前最大值的最开始和最后下标
2. 从右向左找大于当前最小值的最开始和最后下标
结果即为上面四个下标的最小和最大值
```python
class Solution:
    def subSort(self, array: List[int]) -> List[int]:
        if not array:
            return [-1, -1]
        ls, le, rs, re = -1, -1, -1, -1
        mx = array[0]
        for i in range(1, len(array)):
            if array[i] < mx:
                if ls == -1:
                    ls = i
                le = i
            else:
                mx = array[i]
        mn = array[-1]
        for i in range(len(array) - 1)[::-1]:
            if array[i] > mn:
                if rs == -1:
                    rs = i
                re = i
            else:
                mn = array[i]
        return [min(ls, le, rs, re), max(ls, le, rs, re)]
```
### 方法2(O(NlogN)): 先排序, 然后逐位比较
```python
class Solution:
    def subSort(self, array: List[int]) -> List[int]:
        if not array:
            return [-1, -1]
        sa = sorted(array)
        i, j = 0, len(array) - 1
        while i < len(array) and array[i] == sa[i]:
            i += 1
        while j >= 0 and array[j] == sa[j]:
            j -= 1
            if i >= j:
                return [-1, -1]
        return [i, j]
```