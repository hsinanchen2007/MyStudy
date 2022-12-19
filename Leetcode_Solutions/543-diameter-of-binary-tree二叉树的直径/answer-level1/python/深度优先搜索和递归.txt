### 解题思路
两个思想：深度优先搜索和递归。
还有一个要点就是，直径和最大深度的关系。当前节点的直径，要不然就是某个孩子节点的直径，要不然就是当前节点的左孩子子树深度+右孩子子树深度。而最原始的直径算法就是左孩子子树深度+右孩子子树深度。想清楚这个，就知道怎么写递归了。
另外，用一个全局变量来保存之前递归中的最大直径值，能简化代码。（之前自己用的是列表保存所有的直径，，，浪费空间……）
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        def depth(node):
            if not node:
                return 0
            L = depth(node.left)
            R = depth(node.right)
            self.ans = max(self.ans, L+R)
            return max(L,R)+1
        depth(root)
        return self.ans
```