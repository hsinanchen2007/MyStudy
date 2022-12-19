### 解题思路
用先序遍历+标记的方法判断 t是否为s的子串，进而判断t是否为s的子树

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
      
        inorderS=self.inorder(s)
        inorderT=self.inorder(t)
        return inorderT in inorderS
        
    def inorder(self,root):
        if not root:
            return "#"
        return "*"+str(root.val)+self.inorder(root.left)+self.inorder(root.right)

```