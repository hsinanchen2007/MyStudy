这一题我的想法是这样的（拿题就做，没有考虑许多要求）
```
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head:
            return None
        cur = head
        s = 0
        while cur is not None:
            s += 1
            cur = cur.next
        index = s - n
        if index <= 0:
            return head.next
        nc = head
        for i in range(index - 1):
            nc = nc.next
        nc.next = nc.next.next
        return head
```
特殊情况：链表为空；待删除的是head
想法：先通过遍历求出Length,再通过n求出待删除的正向index
随后通过另一次遍历，定位待删除元素的前一个元素，执行删除操作即可