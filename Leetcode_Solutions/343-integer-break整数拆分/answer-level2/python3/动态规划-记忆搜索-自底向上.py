递归----超时
```
class Solution:
    def integerBreak(self, n):
        return self.breakIntreger(n)

    def breakIntreger(self, n):
        if n == 1:
            return 1
        result = 0

        for i in range(1, n):
            result = (max([result, i * (n - i), i * self.breakIntreger(n - i)]))
        return result
```
加入记录变量--记忆搜索
```
class Solution:
    def integerBreak(self, n):
        self.re = [0 for i in range(n + 1)]
        return self.breakIntreger(n)

    def breakIntreger(self, n):
        if n == 1:
            return 1
        result = 0
        if self.re[n] is not 0:
            return self.re[n]
        for i in range(1, n):
            result = (max([result, i * (n - i), i * self.breakIntreger(n - i)]))
        self.re[n] = result
        return result
```
动态规划，自底向上
    def integerBreak2(self, n):
        if n == 1:
            return 1
        record = [-1 for _ in range(n + 1)]
        for i in range(2, n + 1):
            for j in range(1, i):
                record[i] = max([record[i], j * (i - j), j * record[i - j]])
        return record[n]


