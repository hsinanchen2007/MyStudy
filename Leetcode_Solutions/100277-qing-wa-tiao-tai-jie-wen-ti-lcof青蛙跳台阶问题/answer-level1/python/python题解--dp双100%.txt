### 解题思路
![image.png](https://pic.leetcode-cn.com/d311fbca9483b5f4c862505425863e917a905a08b2507eb81b5a5f36ae13aff6-image.png)

- 我们来分析问题
- 首先看下最简单的情况:如果只有一级台阶的时候,显然只有一种跳法.如果有两级台阶,那就有两种跳法,一种是分两次跳,一次跳一级.另一种是一次跳两级.
- 下面我们看下一般的情况,有`n`级台阶,当`n>2`时,第一次跳有两种不同的选择:
1. 一是第一次跳一级,此时的跳法数目等于后面的`n-1`级台阶的跳法数目
2. 二是第一次跳两级,此时的跳法数目等与后面的`n-2`级台阶的跳法数目
- 所以可以总结出来了公式:`f(n) = f(n-1) + f(n-2)`,很显然这是一个递归过程,直接码代码很简单.
- 我们采用dp的思路来求解,减少重复的运算

### dp代码

```python
class Solution(object):
    def numWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1
        if n == 1:
            return 1
        f_0 = 1
        f_1 = 1
        f_n = 0
        for i in range(2,n+1):
            f_n = f_0 + f_1
            f_0 = f_1
            f_1 = f_n
        return f_n % 1000000007


            
```