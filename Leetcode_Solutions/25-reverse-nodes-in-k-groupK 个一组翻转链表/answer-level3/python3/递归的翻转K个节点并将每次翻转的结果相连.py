
```python []
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        def callength(l):
            length=0
            while l:
                l=l.next
                length+=1
            return length
        length=callength(head)
        if length < k:
            return head
        if length == k:
            y = None
            while head:
                x=head
                head=x.next
                x.next=y
                y=x
            return y
        q=None
        for i in range(k):
            p=head
            head=p.next
            p.next=q
            q=p
        l=q
        while q.next:     #将q定位至已翻转链表的最后一个节点
            q=q.next
        q.next=self.reverseKGroup(head,k)     #连接
        return l
```
