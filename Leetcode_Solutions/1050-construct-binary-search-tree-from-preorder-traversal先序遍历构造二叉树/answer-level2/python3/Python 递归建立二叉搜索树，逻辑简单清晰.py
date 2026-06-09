数列第一位为根，小于根的数列为左子树，大于根的数列为右子树

如果数列为空，则得到最小的子树 None

```python
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        root = TreeNode(preorder[0])
        preorder_left = [val for val in preorder if val < root.val]
        preorder_right = [val for val in preorder if val > root.val]
        root.left = self.bstFromPreorder(preorder_left)
        root.right = self.bstFromPreorder(preorder_right)
        return root
```
