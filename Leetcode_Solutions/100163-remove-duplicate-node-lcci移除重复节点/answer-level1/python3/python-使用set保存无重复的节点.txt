
凑活使用啦

```
class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head:
            return head
        node_set = {head.val}
        prev, cur = head, head.next
        while cur:
            if cur.val in node_set:
                prev.next = cur.next
                del cur
                cur = prev.next
            else:
                node_set.add(cur.val)
                prev, cur = cur, cur.next
        return head
```
