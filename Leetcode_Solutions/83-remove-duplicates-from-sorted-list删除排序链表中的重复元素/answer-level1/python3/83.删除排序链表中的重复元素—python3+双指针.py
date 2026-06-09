
1.定义两个快慢指针同时指向头节点
2.当值不相等时链接慢指针的下一个节点到fast节点
3.bingo
```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        fast,slow=head,head
        while fast:
            if fast.val!=slow.val:
                slow.next=fast
                fast=fast.next
                slow=slow.next
            else:
                fast=fast.next
        return head
```
