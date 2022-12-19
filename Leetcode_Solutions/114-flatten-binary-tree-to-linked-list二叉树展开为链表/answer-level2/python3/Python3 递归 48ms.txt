思路：把左右子树变成单链表的形式，然后把左子树插入右子树。

```python3 []
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root or (root.left is None and root.right is None):
            return
        else:
            self.flatten(root.left)
            self.flatten(root.right)
            if root.left is None:
                return
            else:
                temp = root.right
                root.right = root.left
                root.left = None
                p = root.right
                while p.right != None:
                    p = p.right
                p.right = temp
                return
```