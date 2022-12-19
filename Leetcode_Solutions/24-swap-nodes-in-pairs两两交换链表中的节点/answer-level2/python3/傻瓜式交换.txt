```

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        head_pre=ListNode(0)
        head_pre.next=head
        p=head_pre
        while p :
            i=p.next
            
            if i:
                #print(i.val)
                j=i.next
               
                if j: 
                    #print(j.val)
                    k=j.next
                    #print(k)
                    p.next=j
                    j.next=i
                    i.next=k
                    p=p.next.next
                else:
                    break
            else:
                break

        return head_pre.next
```
