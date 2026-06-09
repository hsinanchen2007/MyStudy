方法同官方，代码不算精简，但是易懂

```python []
def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry=0
        head=p=ListNode(0)
        while l1 or l2 :
            if l1 and l2 :
                p.val=(l1.val+l2.val+carry)%10
                carry=int((l1.val+l2.val+carry)/10)
                l1=l1.next
                l2=l2.next
                if l1 or l2 or carry:
                    p.next=ListNode(carry)
                    p=p.next
            elif not l1  and l2 :
                p.val=(l2.val+carry)%10
                carry=int((l2.val+carry)/10)
                l2=l2.next
                if l2 or carry:
                    p.next=ListNode(carry)
                    p=p.next
            elif not l2 and l1:
                p.val=(l1.val+carry)%10
                carry=int((l1.val+carry)/10)
                l1=l1.next
                if l1 or carry:
                    p.next=ListNode(carry)
                    p=p.next

        return head
```





