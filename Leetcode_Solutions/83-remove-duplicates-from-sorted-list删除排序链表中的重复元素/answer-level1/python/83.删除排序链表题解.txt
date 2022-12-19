```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head: return head
        pre, post = head, head.next
        while post is not None:
            if pre.val == post.val:
                pre.next = post.next
                post = pre.next
            else:
                post = post.next
                pre = pre.next
        return head

```