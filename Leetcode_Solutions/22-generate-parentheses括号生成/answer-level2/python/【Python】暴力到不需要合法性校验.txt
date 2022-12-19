## 解题思路

方法是比较暴力的，但是省略了合法性的校验。

在`n - 1`场景下，每一个有效组合的每一个缝隙都插一个`()`进去，再去重，就是答案。

## 代码

```python3
from functools import lru_cache


@lru_cache(maxsize=None)
def generate(n):
    if n == 1:
        return ('()', )
    results = set()
    for i in generate(n - 1):
        for j in range(len(i)):
            prefix, postfix = i[:j], i[j:]
            results.add(prefix + '()' + postfix)
    return frozenset(results)


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        return list(generate(n))
```

> 执行用时 : `40 ms`, 在所有 Python3 提交中击败了`66.09%`的用户
> 内存消耗 : `14 MB`, 在所有 Python3 提交中击败了`5.03%`的用户

## 另一种写法

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        last, now = set(), set()
        for i in range(n):
            if last:
                for i in last:
                    for j in range(len(i)):
                        prefix, postfix = i[:j], i[j:]
                        now.add(prefix + '()' + postfix)
                last, now = now, last
                now.clear()
            else:
                last.add('()')
        return list(last)
```

> 执行用时 : `44 ms`, 在所有 Python3 提交中击败了`48.48%`的用户
> 内存消耗 : `13.9 MB`, 在所有 Python3 提交中击败了`5.03%`的用户

理论上，这种写法是比上一种效率更高的。但是……实际上还得看leetcode服务器的脸色。
至于“内存消耗”，我已懒得吐槽。