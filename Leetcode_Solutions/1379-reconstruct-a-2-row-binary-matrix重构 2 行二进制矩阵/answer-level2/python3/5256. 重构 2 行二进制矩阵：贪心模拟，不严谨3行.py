![image.png](https://pic.leetcode-cn.com/3b36091676c680c4cb3403ce79d5bc0527acdf6ba1a7375a3bf97ca1422c1160-image.png)


第一行直接放， 第二行用`colsum`减去第一行来放，然后验证第二行数字并输出，808ms，仅供参考。

```python []
class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        A = [1] * upper + [0] * (len(colsum) - upper)
        B = [c - a for a, c in zip(A, colsum)]
        return [A, B] if sum(B) == lower else []
```

经大佬指出，这代码虽然可以AC，但其实是不是正确的，起码过不了`u=2, l=0, c=[0, 2]`数据，所以补了一个正解，但没这么短了，速度倒是基本没差。

第一行改成了列大于零时才放，输出是多加了个判断。

```python []
class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        A = []
        for c in colsum:
            if c and upper > 0:
                A += [1]
                upper -= 1
            else:
                A += [0]
        B = [c - a for a, c in zip(A, colsum)]
        return [A, B] if sum(B) == lower and not upper else []
```

