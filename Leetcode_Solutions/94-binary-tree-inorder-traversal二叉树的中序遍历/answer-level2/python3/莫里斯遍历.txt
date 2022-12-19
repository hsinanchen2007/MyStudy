官方题解的莫里斯遍历改变了二叉树的树形结构，虽然也实现了O(1)的空间复杂度对二叉树进行遍历，但是无法将二叉树恢复到原来的形状。
所以这里我写了一个莫里斯遍历的python版，并且实现了树形形状的恢复功能。
```python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> list:
        current = root
        ans = []
        while current is not None:
            if current.left is None:
                ans.append(current.val)
                current = current.right
            else:
                pre = current.left
                while pre.right != None and pre.right != current:
                    pre = pre.right
                if pre.right is None:
                    pre.right = current
                    current = current.left
                else:
                    pre.right = None
                    ans.append(current.val)
                    current = current.right
        return ans
```
