直接从链表头开始交换节点，每交换一次，指针后移两个节点。

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        l = ListNode(-1)
        q=l
        while head:
            if head.next is None:
                break
            p = head.next
            head.next = p.next
            p.next = head
            l.next = p
            l=l.next.next
            head = head.next
        return q.next