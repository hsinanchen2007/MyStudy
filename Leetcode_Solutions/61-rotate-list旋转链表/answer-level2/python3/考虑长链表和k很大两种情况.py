在获取链表长度时，能得到第k个节点直接跳出，击败95%
```
class Solution(object):
    def rotateRight(self, head, k):
        if not head :return head
        cur=fast=slow=head
        count=0
        while cur:
            count+=1
            if count==k+1:
                fast=cur
                break
            cur=cur.next            
        else:
            for i in range(k%count):
                fast=fast.next
        while fast.next:
            fast=fast.next
            slow=slow.next
        if slow==fast:return head
        res=slow.next 
        slow.next=None
        fast.next=head
        return res 
```
