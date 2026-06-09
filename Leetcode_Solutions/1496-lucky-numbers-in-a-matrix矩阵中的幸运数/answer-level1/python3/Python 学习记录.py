### 解题思路
没有充分利用题目的条件,copy一下别人的作为记录

*行最小值，列最大值，都是可以分别算出来的。在元素唯一的情况下，同时满足两种条件，取交集即可；即使元素不唯一，取坐标交集也行，操作上麻烦些。Python的优势在于，求列最大值时有zip和推导式这些方便的手段。*

zip 加参数分配，非常pythonic
#### 集合操作
    s.union(t)
    s | t
    返回一个新的 set 包含 s 和 t 中的每一个元素
    
    s.intersection(t)
    s & t
    返回一个新的 set 包含 s 和 t 中的公共元素
    
    s.difference(t)
    s-t

我的
```python3
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        res = []
        for array in matrix:
            half_lucky = min(array)
            half_index = array.index(min(array))
            if half_lucky == max([i[half_index]for i in matrix]):
                res.append(half_lucky)
        return res
```
别人的
```python3
class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        mins = {min(rows) for rows in matrix}
        maxes = {max(columns) for columns in zip(*matrix)}
        return list(mins & maxes)
```
