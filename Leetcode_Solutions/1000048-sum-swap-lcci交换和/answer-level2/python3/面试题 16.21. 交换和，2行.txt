提示内部错误，还没提交就盲发题解了。

思路倒是也不复杂，求出两组数据的差再除以2，把一边数据存进哈希集合，然后找出另一边数据就行了。

```python []
class Solution:
    def findSwapValues(self, array1: List[int], array2: List[int]) -> List[int]:
        s, d = {*array1}, (sum(array2) - sum(array1)) / 2
        return next([i - d, i] for i in array2 if i - d in s)
```

类型严谨的判断得三行：

```python []
class Solution:
    def findSwapValues(self, array1: List[int], array2: List[int]) -> List[int]:
        s1, s2 = sum(array1), sum(array2)
        a, d = {*array1}, (s2 - s1) // 2
        return s2 - s1 == 2 * d and next(([i - d, i] for i in array2 if i - d in a), []) or []
```
