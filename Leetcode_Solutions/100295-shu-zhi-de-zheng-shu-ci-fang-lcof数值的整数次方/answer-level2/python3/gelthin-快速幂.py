### 解题思路
阿里机试题的一个中间步骤。

同习题 [50. Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)

两种解法： 循环 or 递归




### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        ## 快速幂算法
        if n == 0:
            return 1
        isN = False  # is Negative
        if n < 0:
            isN = True
            n = -n
        res = 1
        while n > 0:
            if n%2 != 0:
                res *= x
            x = x*x
            n = n//2
        if isN:
            res = 1/res
        return res

        
            

        
```