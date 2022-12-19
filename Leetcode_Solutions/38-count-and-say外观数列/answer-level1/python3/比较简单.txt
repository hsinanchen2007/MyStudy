### 解题思路
比较暴力

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        o = '1'
        if n == 1:
            return o
        for _ in range(n-1):
            p = o[0]
            r = ''
            x = 0
            for i in o:
                if i == p:
                    x += 1
                else: 
                    r += str(x) + p
                    p = i
                    x = 1 
            r +=  str(x) + p
            o = r

        return o
```