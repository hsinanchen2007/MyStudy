### 解题思路
    # 函数功能:输入root,翻转此二叉树
    # 递推公式:inverTree(root) =  翻转左子树inverTree(root.left),翻转右子树inverTree(root.right),
    #          root.left = 右子树 and root.right = 左子树
    #终止条件: 节点为None

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # 函数功能:输入root,翻转此二叉树
    # 递推公式:inverTree(root) =  翻转左子树inverTree(root.left),翻转右子树inverTree(root.right),
    #          root.left = 右子树 and root.right = 左子树
    #终止条件: 节点为None
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return
        root.left,root.right = self.invertTree(root.right),self.invertTree(root.left)
        return root
```