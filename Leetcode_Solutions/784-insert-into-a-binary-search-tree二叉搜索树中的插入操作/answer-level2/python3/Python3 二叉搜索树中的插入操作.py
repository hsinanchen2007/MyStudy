### 解题思路
1. 当树不存在时，不能直接返回None，需要将插入的值变为根节点；
2. 若根节点存在，且插入的值小于根节点的值，就递归往左子树里插；
3. 若插入的值大于根节点的值，就递归往右子树里插。
4. 最后返回根节点即可。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            root = TreeNode(val)
        if root.val < val:
            root.right = self.insertIntoBST(root.right, val)
        elif root.val > val:
            root.left = self.insertIntoBST(root.left, val)
        return root
```