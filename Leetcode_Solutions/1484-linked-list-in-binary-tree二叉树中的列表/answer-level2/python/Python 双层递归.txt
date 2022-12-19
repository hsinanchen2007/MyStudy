### 大家好，我的博客是: http://erik-chen.github.io/，欢迎交流！
### 解题思路
1. 外层递归解决链表的头和tree的某个node匹配的问题
2. 内层递归解决链表的每个node和tree的每层node匹配的问题

### 代码

```python3
class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        if root:
            if head.val == root.val:
                if self.f(head, root):
                    return True
            return self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
        return False
    
    def f(self, node, root):
        if not node.next:
            return True
        if root.left and root.left.val == node.next.val and self.f(node.next, root.left):
            return True
        if root.right and root.right.val == node.next.val and self.f(node.next, root.right):
            return True
        return False
```