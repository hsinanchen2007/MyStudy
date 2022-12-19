判断链表有环的操作是:
初始化一个快指针一个慢指针，快指针一次走 2 格，慢指针一次走 1 格。
如果快指针为空或它的下一个节点为空，则该链表无环，否则该链表有环。

```Python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head == None or head.next == None:
            return False
        slow = head
        fast = head.next
        while slow != fast:
            if fast == None or fast.next == None:
                return False
            fast = fast.next.next
            slow = slow.next
        return True
```