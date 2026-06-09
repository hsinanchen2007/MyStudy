## 思路

利用`DFS`按题目要求建树，

建树过程中用一个集合 `self.values`，记录树中所有的值，

这样可以快速知道一个值在不在树中。

## 代码实现
```Python
class FindElements(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        root.val = 0
        self.values = set()
        def dfs(node):
            if not node:
                return 
            self.values.add(node.val)
            if node.left:
                node.left.val = 2 * node.val + 1
                dfs(node.left)
            if node.right:
                node.right.val = 2 * node.val + 2
                dfs(node.right)
        dfs(root)
        
    def find(self, target):
        """
        :type target: int
        :rtype: bool
        """
        
        return target in self.values

```

## 复杂度分析：
时间复杂度：$O(N)$
空间复杂度：$O(N)$