```python
class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not B:
            return False

        return self._travel(A, B)

    def _travel(self, A, B):
        """前序遍历，判断当前A的节点和B是否同构"""
        if not A:
            return False

        if A.val == B.val and self._is_sub(A.left, B.left) and self._is_sub(A.right, B.right):
            return True

        return self._travel(A.left, B) or self._travel(A.right, B)

    def _is_sub(self, A, B):
        """判断AB同构"""
        if not B:
            return True

        if not A or A.val != B.val:
            return False

        return self._is_sub(A.left, B.left) and self._is_sub(A.right, B.right)
```