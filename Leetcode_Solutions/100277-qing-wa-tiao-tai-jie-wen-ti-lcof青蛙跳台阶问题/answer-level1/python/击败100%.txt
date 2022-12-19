一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
假设对于第n级台阶，总共有f(n)种跳法.

那么f(n) = f(n-1) + f(n-2)，其中f(1)=1,f(2)=2

### 代码

```python
class Solution(object):
    def numWays(self, n):
        if n == 0: return 1
        f1 = 1
        f2 = 2
        if n == 1: return f1
        if n == 2: return f2
        for _ in range(n-2):
            f2, f1 = f1+f2, f2
        return f2 % 1000000007
```