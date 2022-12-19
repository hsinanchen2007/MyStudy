跟108差不多。。把直接算中点换成快慢指针就ok
```
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
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        
        def helper(head):
            if not head:
                return
            prev, slow, fast = None, head, head

            while(fast and fast.next):
                prev = slow
                slow = slow.next
                fast = fast.next.next
            if prev:
                prev.next = None

            mid = slow.next
            root = TreeNode(slow.val)
            if head == slow:
                return root
            
            root.left = helper(head)
            root.right = helper(mid)
            return root

        return helper(head)
```
