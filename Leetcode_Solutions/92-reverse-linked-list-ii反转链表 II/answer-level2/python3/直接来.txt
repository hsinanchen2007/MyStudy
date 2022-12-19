```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m==n:
            return head
        inx=1
        p=head
        p1=None
        while inx<=n:
            if inx==m-1:
                p1=p
                p=p.next
                
            elif inx==m:
                p2=p
                tp=p2
                p=p.next
                
            elif m<inx<n:
                pn=p.next
                p.next=tp
                tp=p
                p=pn
                
            elif inx==n:
                pn=p.next
                p.next=tp
                if p1:
                    p1.next=p
                p2.next=pn
            else:
                p=p.next
            inx+=1
        if p1:
            return head
        else:
            return p
```
