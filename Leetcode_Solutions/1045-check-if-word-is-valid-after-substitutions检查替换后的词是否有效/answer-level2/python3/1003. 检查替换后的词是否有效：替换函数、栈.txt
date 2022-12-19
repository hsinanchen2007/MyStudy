![image.png](https://pic.leetcode-cn.com/2b871f75ed27745abd805e9f8fddef79c1e106f28431403799ec00b19774234e-image.png)


大佬的写法（90%左右）

```python [1]
class Solution:
    def isValid(self, S: str) -> bool:
        while 'abc' in S:
            S = S.replace('abc', '')
        return not S
```

标准写法（40%左右很慢）

```python [2]
class Solution:
    def isValid(self, S: str) -> bool:
        s = ['']
        for c in S:
            s += [c]
            if s[-1] == 'b' and s[-2] != 'a' or s[-1] == 'c' and s[-2] != 'b':
                return False
            if c == 'c':
                s = s[: -3]
        return not s[1: ]
```

或者用n//3个abc作为子串去完全匹配S也差不多,但就更复杂了，还是python大法好啊。