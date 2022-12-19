### 解题思路
1.若根结点为空，则必然平衡；
2.若不为空，则必然存在左子树和右子树，计算其高度，看是否平衡；
3.若平衡，则检查其左子树和右子树本身是否平衡；

！高度计算函数思路：
//若根结点为空，则高度为零；
//否则分别计算其左子树和右子树的高度；
//总高度为左右子树高度最大值加1，包含根结点高度；

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True     
        if abs(self.height(root.left) - self.height(root.right)) > 1:
            return False
        else:
            return self.isBalanced(root.left) and self.isBalanced(root.right)
    def height(self, root):
        if not root:
            return 0
        lheight = self.height(root.left)
        rheight = self.height(root.right)
        return max(lheight, rheight) + 1
```