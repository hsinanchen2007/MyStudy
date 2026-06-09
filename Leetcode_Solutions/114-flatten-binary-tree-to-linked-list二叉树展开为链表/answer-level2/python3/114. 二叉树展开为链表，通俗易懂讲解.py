### 解题思路
1. 寻找左子树的最右节点
2. 将右子树挂接在左子树最右节点的后面
3. 将左子树挂在根节点的右子树上
4. 将左子树置为空
5. 遍历右子树，直至右子树中的节点无左子树节点

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        while root:
            if root.left:
                cur = root.left
                while cur.right:
                    cur = cur.right   # 循环一直寻找到左子树的最右节点
                cur.right = root.right  # 将右子树挂接在左子树的最右节点
                root.right = root.left  # 将左子树挂在右子树的节点上
                root.left = None    # 将左子树节点置为空
            root = root.right
        return root
        



```