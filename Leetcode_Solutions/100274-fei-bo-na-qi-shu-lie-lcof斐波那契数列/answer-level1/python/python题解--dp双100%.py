### 解题思路
![image.png](https://pic.leetcode-cn.com/93dd22fb551f655fd274aa353c9680b643c79e01d8e80176675340b866893365-image.png)


- 根据递推公式`f(n) = f(n-1) + f(n-2)`可以很容易写出递归的代码,这里就不写了
- 其实这题是考大家dp的思想,代码直接给出了,很简单
### dp代码

```python
class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        if n == 1:
            return 1
        f_0 = 0
        f_1 = 1
        f_n = 0
        for i in range(2, n+1):
            f_n = f_0 + f_1
            f_0 = f_1
            f_1 = f_n
        return f_n % 1000000007
```