### 解题思路
前序遍历的存储顺序：node->left->right，这个存储顺序同样也是最简单的数据。
递归的思路是用最简单的数据勾勒出解法后，在此基础上重复调用此方法。
注意：每次找到根结点后存到全局列表中，递归的是过程（存储的动作）。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.result = []
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        if root.val is not None:
            self.result.append(root.val)
        if root.left is not None:
            self.preorderTraversal(root.left)
        if root.right is not None:
            self.preorderTraversal(root.right)
        return self.result
```