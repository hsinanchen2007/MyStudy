### 解题思路
简单递归，直接上代码吧

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        def isSub(head1:ListNode, root1:TreeNode) -> bool:
            if not head1:
                return True
            if not root1:
                return False
            if (head1.val != root1.val):
                return False
            return isSub(head1.next, root1.left) or isSub(head1.next, root1.right)
        
        if not head:
            return True
        if not root:
            return False
        return isSub(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
```