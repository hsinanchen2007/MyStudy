### 解题思路
![image.png](https://pic.leetcode-cn.com/212d4a04292d5e30dda5bfcd161e847c1e8cff4600338204bb19e006d0a7c344-image.png)

- 这个题和剑指offer的跳台阶是一样的
- 每次可以爬一个或者两个台阶,所以对于第`n`阶台阶我们有,`f(n) = f(n-1) + f(n-2)`,这就是递归式了
- 是不是很像斐波那契数列啊  哈哈
- 开始分析,当n=1时,显然`f(1)=1`,当n=2时可以一次跳一个,也可以一次跳两个,所以有两种方法,故`f(2)=2`,这样边界条件就设定好了

### 代码

```python
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        f_1 = 1
        f_2 = 2
        if n == 0:
            return None
        if n == 1:
            return f_1
        if n == 2:
            return f_2
        for i in range(3,n+1):
            f_n = f_2 + f_1
            f_1 = f_2
            f_2 = f_n
        return f_n
        
            
```