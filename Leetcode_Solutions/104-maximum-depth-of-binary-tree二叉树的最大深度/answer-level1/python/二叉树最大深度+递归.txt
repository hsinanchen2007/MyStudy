### 解题思路
1、设置全局变量，最大深度
2、递归，返回左右节点的高度
3、左右节点的高度与全局最大深度比较，取最大赋值全局变量

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def add(root,r=0):
            if not root:
                self.dep = max(self.dep,r)
                return 
            
            add(root.left,r+1)
            add(root.right,r+1)
        
        self.dep = 0
        add(root)
        
        return self.dep
```