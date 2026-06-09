### 解题思路
此处撰写解题思路
新手上路求轻喷
利用递归，nodeCorrect()用于返回该节点与其左右孩子的值是否相同，如child有None则视为与parent相同
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root:
            return True
            
        def nodeCorrect(root):
            if (root == None):
                return True
            if (root.left and (root.left.val != root.val)):
                return False
            elif (root.right and (root.right.val != root.val)):
                return False
            else:
                return True
        return (nodeCorrect(root) and self.isUnivalTree(root.left) and self.isUnivalTree(root.right))

```