运行注释部分没问题，但是使用 n and (n = n + self.sumNums(n-1)), 提示语法出错，Python 小白，求解，拜谢><

```
class Solution:
    def sumNums(self, n: int) -> int:

        n and (n = n + self.sumNums(n-1))
        # if n == 1:
        #     return n
        # n = n + self.sumNums(n-1)
        # print(n)
        return n
```
