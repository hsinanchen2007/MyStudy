一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
$$f(n)=f(n-1)+f(n-2)$$

### 代码

```python
class Solution(object):
    def fib(self, n):
        f1 = 0
        f2 = 1
        if n == 0: return f1
        elif n == 1: return f2
        for _ in range(n-1):
            f2, f1 = f1+f2, f2
        return f2 % 1000000007
```