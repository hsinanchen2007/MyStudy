
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
       
        #快慢指针
         
        head_pre = ListNode(0)
        head_pre.next = head
        fast = slow = slow_pre =  head_pre
        for i in range(n-1):
            fast=fast.next
        while fast.next:
            fast=fast.next
            slow_pre=slow
            slow=slow.next
        slow_pre.next=slow.next
        return head_pre.next