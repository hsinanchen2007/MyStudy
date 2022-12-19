
简单数学知识得到非快乐数会最终进入死循环4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4
用合适的临界值终止循环
```
代码块
class Solution:
    def isHappy(self, n: int) -> bool:
        k = 0
        while True:
            k += 1
            s = 0
            for i in str(n):
                s += int(i)**2
            if s == 1:
                return True
            elif k > 10:
                return False
            else: 
                n = s

       
```
代码块
```
```
