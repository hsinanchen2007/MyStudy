## 审题

行最小值，列最大值，都是可以分别算出来的。在元素唯一的情况下，同时满足两种条件，取交集即可。

Python的优势在于，求列最大值时有`zip`和推导式这些方便的手段。

## 参考答案

```python
class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        mins = {min(rows) for rows in matrix}
        maxes = {max(columns) for columns in zip(*matrix)}
        return list(mins & maxes)
```

---

> 执行用时 : `44 ms`, 在所有 Python3 提交中击败了`100.00%`的用户
> 内存消耗 : `13.8 MB`, 在所有 Python3 提交中击败了`100.00%`的用户

## 如果元素不唯一（2020年3月20日补充）

即使元素不唯一，相同思路，取坐标交集也行。
但操作上过于麻烦，所以还不如常规做法。

```python
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        mins = [min(rows) for rows in matrix]
        maxes = [max(columns) for columns in zip(*matrix)]

        lucky = []
        for i, row in enumerate(matrix):
            for j, value in enumerate(row):
                if value == mins[i] and value == maxes[j]:
                    lucky.append(value)
        return lucky
```