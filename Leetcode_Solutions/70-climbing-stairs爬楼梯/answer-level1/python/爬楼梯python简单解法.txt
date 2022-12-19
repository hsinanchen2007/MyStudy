### 解题思路
不知道为什么现在不能用缓存了 换了一种做法 就是简单的斐波那契数列

### 代码

```python
# from functools import lru_cache

class Solution:
    # @lru_cache(10**8)
    def climbStairs(self, n):
        climb={}
        climb[0]=0
        climb[1]=1
        climb[2]=2
        for i in range(3,n+1):
            climb[i] = climb[i-1]+climb[i-2]
        return climb[n]

```