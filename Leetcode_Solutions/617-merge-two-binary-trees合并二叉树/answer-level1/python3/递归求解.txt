### 解题思路
大概思路：
1.合并根节点的值作为新树的根
2.新树根节点的左子树 为第一棵树和第二棵树的左子树的合并，故而这里直接递归，右树同理

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1 and not t2:
            return t1
        if not t1:
            return t2
        if not t2:
            return t1
        newtree = TreeNode(t1.val+t2.val)
        newtree.left = self.mergeTrees(t1.left,t2.left)
        newtree.right = self.mergeTrees(t1.right,t2.right)
         
        return newtree
```