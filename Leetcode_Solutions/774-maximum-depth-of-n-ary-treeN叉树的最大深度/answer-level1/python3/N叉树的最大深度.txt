### 解题思路
我的思路：
本质和求二叉树的高度是一样的,递归求解.
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

```
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        children = root.children
        depth = 0
        for i in range(len(children)):
            depth = max(self.maxDepth(children[i]),depth)
        return depth+1
```