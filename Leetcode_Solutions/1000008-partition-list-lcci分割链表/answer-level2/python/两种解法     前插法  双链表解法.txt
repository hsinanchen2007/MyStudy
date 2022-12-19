```
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        # 解题思路：小于x的移到最前面, 前插法实现
        # 注意：保持 head 始终是头结点
        if not head:
            return None
        cur = head
        while cur.next:
            if cur.next.val < x:
                temp = cur.next
                cur.next = temp.next
                temp.next = head
                head = temp
            else:
                cur = cur.next
        return head
```
```
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        # 双链表实现，小于x的组成一链表，大于x的组成另一链表，然后两链表拼接
        if not head:
            return None
        fnode = ListNode(-1)
        snode = ListNode(-1)
        first = fnode
        second = snode
        while head:
            if head.val < x:
                first.next = head
                first = first.next
            else:
                second.next = head
                second = second.next
            head = head.next

        first.next = snode.next
        second.next = None

        return fnode.next
```
