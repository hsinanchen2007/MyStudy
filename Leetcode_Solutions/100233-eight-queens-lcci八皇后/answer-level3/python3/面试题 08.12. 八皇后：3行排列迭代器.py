### 解题思路

先输出个迭代器，然后验证不在同一个斜线上就可以输出了，因为是遍历后验证，其实是非常慢的方法。

```python []
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        for arr in itertools.permutations(range(n)):
            if all(abs(arr[i] - arr[j]) != j - i for i, j in itertools.combinations(range(n), 2)):
                yield ("." * i + "Q" + "." * (n - i - 1) for i in arr)
```
```python []
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        return (
            ("." * i + "Q" + "." * (n - i - 1) for i in arr)
            for arr in itertools.permutations(range(n))
            if all(
                abs(arr[i] - arr[j]) != j - i
                for i, j in itertools.combinations(range(n), 2)
            )
        )
```

### 标准回溯

```python []
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        def f(a, b, c):
            if (j := len(a)) == n:
                ans.append(a)
            else:
                for i in range(n):
                    i not in a and i - j not in b and i + j not in c \
                    and f({**a, **{i: 0}}, {**b, **{i - j: 0}}, {**c, **{i + j: 0}})
        f({}, {}, {})
        return (("." * i + "Q" + "." * (n - i - 1) for i in arr) for arr in ans)
```
```python []
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        def f(a, b, c):
            if (j := len(a)) == n:
                ans.append(a)
            else:
                for i in range(n):
                    i not in a and i - j not in b and i + j not in c \
                    and f([*a, i], [*b, i - j], [*c, i + j])
        f([], [], [])
        return (("." * i + "Q" + "." * (n - i - 1) for i in arr) for arr in ans)
```
