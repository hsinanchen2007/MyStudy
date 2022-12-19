### 解题思路
1. 当节点为空时，返回None
2. 当root.val<L时，说明左子树都不在[L,R]之间，只找右子树
3. 当root.val>R时，说明右子树都不在[L,R]之间，只找左子树
4. 递归的关键是只关注当下，现在这个情况是root.val属于[L,R]，那么这是我们需要的节点，把它作为根节点，然后找他的左右子树就可以了

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        if not root:
            return None
        if root.val<L:
            return self.trimBST(root.right, L, R)
        if root.val>R:
            return self.trimBST(root.left, L, R)
        new_tree = TreeNode(root.val)
        new_tree.left = self.trimBST(root.left, L, R)
        new_tree.right = self.trimBST(root.right,L, R)
        return new_tree
```