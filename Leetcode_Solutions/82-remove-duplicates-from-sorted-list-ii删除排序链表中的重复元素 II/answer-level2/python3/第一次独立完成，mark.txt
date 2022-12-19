```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        pre=None
        current=head
        while current!=None and current.next!=None:
            if current.val!=current.next.val:
                pre=current
                current=current.next
            else:
                temp=current.next
                while temp.val==current.val:
                    if temp.next!=None:
                        temp=temp.next
                    else:
                        temp=None
                        break
                current=temp
                if pre==None:
                    head=current
                    pre=None
                else:
                    pre.next=current
        return head
```
