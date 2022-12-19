
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def __init__(self):
        self.head=ListNode(0)
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        p=self.head
        p.next=head
        i=0
        while p:
            p=p.next
            i+=1
        p=self.head
        t=0
        while True:
            if t==i-n-1:
                p.next=p.next.next
                return self.head.next
            p=p.next
            t+=1

```

方法二：
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        a=ListNode(0)
        a.next=head
        p=q=a
        i=0
        while i<n:
            p=p.next
            i+=1
        while p.next:
            p=p.next
            q=q.next
        q.next=q.next.next
        return a.next
```

