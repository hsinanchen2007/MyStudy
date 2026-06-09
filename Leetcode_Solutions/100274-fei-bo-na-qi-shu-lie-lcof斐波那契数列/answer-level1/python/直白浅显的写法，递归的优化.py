# 思路

**对最直接浅显的递归写法进行优化**
内部定义一个辅助helper函数
利用一个初始化后的数组进行存储计算后的数值，可以有效避免递归中某些值的反复计算，最后别忘了取余；
节省空间，提高性能。
这不是性能最优的解法，但在编码和思想上的难度应该很低。

# 代码
```
class Solution(object):
    def fib(self, n):
        sets = [0,1,1]
        def helper(n):
            if n<len(sets):
                return sets[n]
            sets.append(helper(n-1)+helper(n-2))
            return sets[n]%1000000007

        return helper(n)
```

