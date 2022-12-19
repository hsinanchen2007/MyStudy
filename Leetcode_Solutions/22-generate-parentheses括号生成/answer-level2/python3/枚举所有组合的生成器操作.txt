### 解题思路
数字每加1，就会增加一个"()"，考虑下这个"()"应该加到什么位置，枚举所有的排列
f(0): ""
f(1): "("f(0)")"
f(2): "("f(0)")"f(1), "("f(1)")"
f(3): "("f(0)")"f(2), "("f(1)")"f(1), "("f(2)")"
f(n) = "("f(0)")"f(n-1) , "("f(1)")"f(n-2) "("f(2)")"f(n-3) ... "("f(i)")"f(n-1-i) ... "(f(n-1)")"


### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def genertor(n):
            if n==0:
                yield ''
            for i in range(n):
                for s1 in genertor(i):
                    for s2 in genertor(n-1-i):
                        yield '('+s1+')'+s2
        return list(genertor(n))
```