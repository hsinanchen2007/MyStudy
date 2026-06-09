
```
class Solution:
    def tribonacci(self, n: int) -> int:
        a = {0: 0, 1: 1, 2: 1}
        for i in range(3, n + 1):
            a[i] = a[i - 1] + a[i - 2] + a[i - 3]
        return a[n]
        #打印上面的n = 37时的a.values()就可以得到打表用的列表了。
```


```
class Solution:
    def tribonacci(self, n: int) -> int:
        return [0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513, 35890, 66012, 121415, 223317, 410744, 755476, 1389537, 2555757, 4700770, 8646064, 15902591, 29249425, 53798080, 98950096, 181997601, 334745777, 615693474, 1132436852, 2082876103][n]
```

```
class Solution:
    def __init__(self):
        self.d = {}
        
    def tribonacci(self, n: int) -> int:
        if n not in self.d:
            self.d[n] = [0, 1, 1][n] if n < 3 else self.tribonacci(n - 1) + self.tribonacci(n - 2) + self.tribonacci(n - 3)
        return self.d[n]
```
