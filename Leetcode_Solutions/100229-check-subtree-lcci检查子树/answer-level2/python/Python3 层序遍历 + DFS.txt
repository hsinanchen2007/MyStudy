整体思路：先是边界输入判断，然后使用层序遍历所有节点，并将每个节点传入辅助函数 `check()`，以 DFS 的方式递归判断结果。

![批注 2020-03-23 214551.png](https://pic.leetcode-cn.com/6e837f4592b0c85d3a84a9a5429a7eb3a3ff9863f539cce253e6449f6dbf935f-%E6%89%B9%E6%B3%A8%202020-03-23%20214551.png)


```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def checkSubTree(self, t1: TreeNode, t2: TreeNode) -> bool:
        
        def check(root, sub) -> bool:
            if not root:
                return False if sub else True
            if (root and not sub) or (root.val != sub.val):
                return False
            return check(root.left, sub.left) and check(root.right, sub.right)

        if not t1: return False
        if not t2: return True

        queue = [t1]
        while queue:
            next_queue = []
            while queue:
                node = queue.pop()
                if check(node, t2): 
                    return True
                if node.left: next_queue += [node.left]
                if node.right: next_queue += [node.right]
            queue = next_queue
        
        return False
```
