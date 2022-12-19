
这题和 剑指offer 面试题26. 树的子结构 类似

```python
class Solution:
    def dfs(self, head, root):
        if not head:
            return True
        if not root:
            return False
        if root.val != head.val:
            return False
        if self.dfs(head.next, root.left) or self.dfs(head.next, root.right):
            return True
        return False
        
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        if not root:
            return False
        if self.dfs(head, root):
            return True
        return self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
            
```
