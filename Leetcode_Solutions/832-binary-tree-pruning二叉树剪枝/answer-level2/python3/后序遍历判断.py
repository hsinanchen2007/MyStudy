### 解题思路
明确问题：二叉树剪支，减掉，值为0且无子树的节点，值为0且子树的节点值均为0
解题思路：后序遍历，判断当前节点值是否为0，左右子节点，是否为空，均是则减掉

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if not root:return None
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        if root.val == 0 and not root.left and not root.right:
            return None
        return root


        
        


        


```