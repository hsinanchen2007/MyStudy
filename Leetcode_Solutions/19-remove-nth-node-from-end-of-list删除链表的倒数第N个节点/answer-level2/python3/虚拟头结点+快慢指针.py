
1. 添加虚拟头结点方便删除第一个节点
2. 找到倒数第n个节点的前一个节点(也就是倒数n+1节点) 指向倒数第n个节点的下一个节点

找到倒数第n+1个节点:

使用两个指针p,q,q先走n+1步,然后p,q一起走直到q走完整条链表,最后p指向的就是倒数k+1个节点

Python代码:
```python
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        p, q = dummy, dummy
        for _ in range(n + 1):
            q = q.next
        while q:
            p = p.next
            q = q.next
        p.next = p.next.next
        return dummy.next

```