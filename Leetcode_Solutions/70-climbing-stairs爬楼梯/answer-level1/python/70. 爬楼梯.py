1. 暴力迭代解决 - 超时了
```
# -*- coding: utf-8 -*

# 暴力解决问题
# 会超时 不是个好的解决方案
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int 
        """
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            return self.climbStairs(n-1) + self.climbStairs(n-2)

print Solution().climbStairs(4)
```

2. dictionary 优化 
- 执行用时: 16 ms, 在所有 Python 提交中击败了93.82%的用户
```
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int 
        """
        Dict = dict(zip([1, 2], [1, 2]))
        if (n > 2):
          i = 3
          while(i <= n):
              Dict[i] = Dict[i - 1] + Dict[i - 2]
              i += 1
        return Dict.get(n)
        

print Solution().climbStairs(4)
```

3. 动态规划 斐波那契数
- 执行用时 : 12 ms, 在所有 Python 提交中击败了98.74%的用户
```
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        p, q = 1, 2
        if n < 3:
            return n
        else:
            for __ in range(3, n + 1):
                p, q = q, p + q
            return q
```