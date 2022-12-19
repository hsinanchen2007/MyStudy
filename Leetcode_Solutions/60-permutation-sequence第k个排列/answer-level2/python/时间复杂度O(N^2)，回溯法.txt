# 经典的回溯法
解题思路：
1. 方法:枚举所有的排列（图的深度遍历），有个全局的计数器，直到计数到k，返回该排列就可以。但是提交后运行超时。
问题：明显该题目是只求第K个排列，不需要枚举所有排列。那么如何提前返回（减枝）呢。

2. 减支方法
- 每个分支的排列数量`count`是可以求出来的，如果k大于count，那么可以后移到下个分支，以此类推。
- 如果小于count，则进入下一层，继续按照上面的规则判断
- 画图看的话很像多叉查找

3. 这种回溯法，写法上都可以有小技巧：比如每次都有path（已经遍历的路径）和remain（剩余需要遍历的节点）
复杂度分析：
- Space：O(N)
- Time: O(N^2) 最坏需要1+2+...+n次比较

```python []
class Solution(object):
    
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        
        def fact(n):
            ret = 1
            while n:
                ret *= n
                n -= 1
            return ret
        
        def dfs(remain, path, k):
            if not remain:
                return path
            
            l = len(remain)
            count = fact(l-1)  # 对于每一层，该层每个分支的数量相当于剩余数量-1的阶乘
            for i in range(l):
                if k > count: # 此处如果k大于该分支排列数量，那么减去该分支
                    k -= count
                else:
                    return dfs(remain[:i]+remain[i+1:], path+remain[i], k)
            
        return dfs([str(i) for i in range(1, n+1)], '', k)
```

