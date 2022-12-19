### 解题思路
-   使用字典记住每个`level`的和值，最后使用最深的`level`减去`level`并乘以和值

### 代码

```python3
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution:
    def depthSumInverse(self, nestedList: List[NestedInteger]) -> int:
        from collections import defaultdict
        max_level = 0
        d = defaultdict(int)

        def dfs(nested, level):
            nonlocal max_level, d
            max_level = max(max_level, level)
            for i in nested:
                if i.isInteger():
                    d[level] += i.getInteger()
                else:
                    dfs(i.getList(), level + 1)

        dfs(nestedList, 1)
        max_level += 1
        ans = 0
        for k, v in d.items():
            ans += (max_level - k) * v
        return ans
```