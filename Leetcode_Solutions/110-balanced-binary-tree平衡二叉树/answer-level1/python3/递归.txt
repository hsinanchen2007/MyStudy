### 解题思路
#一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1:,
#仅仅满足abs(self.getHeight(root.left) - self.getHeight(root.right)) <= 1还不够
#左右子树也需要是平衡二叉树

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1:,
#仅仅满足abs(self.getHeight(root.left) - self.getHeight(root.right)) <= 1还不够
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        else:
            return abs(self.getHeight(root.left) - self.getHeight(root.right)) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)
    

    def getHeight(self,root):
            if not root:
                return 0
            else:
                return 1 + max(self.getHeight(root.left),self.getHeight(root.right))
```