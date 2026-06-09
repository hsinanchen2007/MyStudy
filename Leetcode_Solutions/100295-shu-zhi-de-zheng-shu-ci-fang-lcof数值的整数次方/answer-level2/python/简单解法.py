一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
指数幂的所有边界包括:
- 指数为0的情况，不管底数是多少都应该是1
- 指数为负数的情况，求出的应该是其倒数幂的倒数
- 指数为负数的情况下，底数不能为0

### 代码

```python
class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0: return 1
        flag = 1
        if n < 0:
            n *= -1
            flag = 0
        temp = x
        res = 1
        while(n):
            if n & 1:
                res *= temp
            temp *= temp
            n = n >> 1

        return res if flag else 1.0/res
```