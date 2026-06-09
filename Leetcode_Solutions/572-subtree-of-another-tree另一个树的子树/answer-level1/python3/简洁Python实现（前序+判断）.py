### 解题思路
前序遍历 + 判断同构

### 代码

```python3
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not t:
            return False

        return self._travel(s, t)

    def _travel(self, A, B):
        """前序遍历，判断当前A的节点和B是否同构"""
        if not A:
            return False

        if A.val == B.val and self._is_sub(A.left, B.left) and self._is_sub(A.right, B.right):
            return True

        return self._travel(A.left, B) or self._travel(A.right, B)

    def _is_sub(self, A, B):
        """判断AB同构"""
        if not A and not B:
            return True
        
        if A and not B:
            return False

        if not A or A.val != B.val:
            return False

        return self._is_sub(A.left, B.left) and self._is_sub(A.right, B.right)
```