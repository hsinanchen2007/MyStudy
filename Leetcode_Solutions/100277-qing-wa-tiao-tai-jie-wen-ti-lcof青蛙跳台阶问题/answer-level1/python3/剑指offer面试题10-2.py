# ### 解题思路
# 用了和10-1不同的方法，👴又好起来🌶

# ### 代码

# ```python3
class Solution:
    def numWays(self, n: int) -> int:
        climb = {}
        climb[0] = 1
        climb[1] = 1
        climb[2] = 2
        for c in range(3,n+1):
            climb[c] = climb[c-1] + climb[c-2]
        return climb.get(n) % 1000000007
# ```