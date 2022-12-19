### 解题思路
栈

### 代码

```python3
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        return self.f(S) == self.f(T)

    def f(self,s):
        res=[]
        for x in s:
            if x == '#' and len(res) != 0:
                res.pop()
            elif x != '#':
                res.append(x)
        return ''.join(res)
```