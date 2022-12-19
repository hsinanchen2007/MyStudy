### 解题思路
辅助队列法和递归法，其实思路是一样的

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric_queue(self, root: TreeNode) -> bool:
        """
        辅助队列法
        """
        if not root:
            return True
        queue = [(root.left,root.right)]
        while queue:
            l, r = queue.pop(0)
            if not l and not r: # 如果左右子节点为空，跳过后面步骤
                continue
            if not l or not r: # 如果左右子节点任意一个为空，则表示不对称
                return False
            if l.val != r.val: # 如果左右子节点的值不等，则表示不对称
                return False
            queue.append((l.left, r.right)) # 将左子树的左节点，和右子树的右节点放入队列
            queue.append((l.right, r.left))
        return True
        
        
        
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        def _recur(l, r):
            if not l and not r:
                return True
            if not l or not r:
                return False
            if l.val != r.val:
                return False
            return _recur(l.left, r.right) and _recur(l.right, r.left)
        return _recur(root.left, root.right)
            
        
        
```