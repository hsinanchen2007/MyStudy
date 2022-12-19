### 解题思路
精华就是利用快慢指针来break出来while循环.

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        def calcSum(n):
            res = 0
            while n > 0:
                res += (n % 10) ** 2
                n //= 10
            # print("res", res)
            return res
        
        s, f = n, n
        while True:
            s = calcSum(s)
            f = calcSum(f)
            f = calcSum(f)
            if s == f:
                break
        return s == 1
```