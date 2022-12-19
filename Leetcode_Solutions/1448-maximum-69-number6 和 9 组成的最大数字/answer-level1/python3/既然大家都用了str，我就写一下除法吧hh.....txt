```python
class Solution:
    def maximum69Number(self, num: int) -> int:
        n = len(str(num))
        res = 0
        for i in range(n, -1, -1):
            temp = num // (10 ** i)
            num = num % (10 ** i)
            if temp == 6:
                res = res * 10 + 9
                res = res * (10 ** i) + num
                break
            else:
                res = res * 10 + temp
        return res
```

str:
```python
class Solution:
    def maximum69Number (self, num: int) -> int:
        num = list(str(num))
        for i in range(len(num)):
            if num[i] == '6':
                num[i] = '9'
                break
        return ''.join(num)
```