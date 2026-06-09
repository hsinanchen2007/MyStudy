```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        length=1
        first=head
        while head.next:
            length+=1
            head=head.next  #统计长度
        head.next=first     #首尾相连
        for _ in range(length-k%length-1):  #找到断开点，注意是n-k%n-1
            first=first.next
        res=first.next
        first.next=None
        return res
            
```
