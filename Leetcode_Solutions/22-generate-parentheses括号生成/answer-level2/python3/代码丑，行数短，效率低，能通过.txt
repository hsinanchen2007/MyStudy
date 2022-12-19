### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> list:
        result = []
        for i in range(pow(2, n*2)):
            x = bin(i)[2: ]
            x = '0' * (2*n-len(x)) + x
            if x.count('1') > n or x.count('0') > n:
                continue

            num = 0
            f = True
            for ch in x:
                if ch == '1':
                    num += 1
                else:
                    num -= 1
                if num < 0:
                    f = False
                    break
            if f:
                result.append(x.replace('1', '(').replace('0', ')'))
        return result
```