### 解题思路
没啥解题思路，看了dalao们的题解，我觉得我不配用python

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = []
        a = list(a)
        b = list(b)
        for i in range(max(len(a), len(b))+1):
            res.append("0")
        if len(a) > len(b):
            for i in range(len(a)-len(b)):
                b.insert(0, '0')
        else:
            for i in range(len(b)-len(a)):
                a.insert(0, '0')
        for i in range(len(a)-1, -1, -1):
            if int(a[i]) + int(b[i]) + int(res[i+1]) == 3:
                res[i+1] = '1'
                res[i] = '1'
            elif int(a[i]) + int(b[i]) + int(res[i+1]) == 2:
                res[i+1] = '0'
                res[i] = '1'
            elif int(a[i]) + int(b[i]) + int(res[i+1]) == 1:
                res[i+1] = '1'
            else:
                res[i+1] = '0'
        for i in range(len(res)):
            if res[i] != '0':
                res = res[i:]
                return "".join(res)
                break
            elif i == len(res) - 1:
                return "0"

```