### 解题思路

一般而言，bfs 需要一个队列，实现和 dfs 不一样的搜索顺序。

下面的程序实现了 bfs 的搜索顺序，却没有使用队列。原因在于一次迭代一层，而不是一个。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from itertools import chain

class Solution:
    
    def maxDepth(self, root: TreeNode) -> int:

        def notNone(x):
            return x is not None

        def bfs(level):
            if len(level) != 0:
                nonlocal depth
                depth += 1
                return bfs(tuple(filter(notNone, 
                    chain(*((n.left, n.right) for n in level)))))

        if not root:
            return 0
        else:
            depth = 0
            bfs((root,))
            return depth

```