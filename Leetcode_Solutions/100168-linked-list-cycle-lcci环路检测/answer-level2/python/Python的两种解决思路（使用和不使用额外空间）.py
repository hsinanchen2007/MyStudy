思路1:
定义一个Hash表，遍历链表，如果当前节点在Hash表中没有记录过，则记录一下，继续遍历，若记录过则表示有环。

思路2: 不用额外的空间
定义两个快、慢指针，快指针一次走两步，慢指针一次走一步，两个指针走到第一次相遇的时候就停下来，把慢指针放到head，之后快慢指针都一步一步走，知道第二次相遇，则为环路入口。

```
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 使用额外空间
        # Hasht = {}
        # while head:
        #     if head not in Hasht:
        #         Hasht[head], head = head, head.next
        #     else:
        #         return head
        # 不使用额外空间
        fast, slow = head, head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if fast == slow:
                slow = head
                while slow != fast:
                    slow, fast = slow.next, fast.next
                return slow
        return None
```



