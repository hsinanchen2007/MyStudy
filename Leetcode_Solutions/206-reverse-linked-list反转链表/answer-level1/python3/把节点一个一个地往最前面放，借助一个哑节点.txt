
class Solution:

    def reverseList(self, head: ListNode) -> ListNode:
        
        if head == None:
            return head
        
        
        dummy = ListNode(-1)
        dummy.next = head
        
        cur = head
        nxt = cur.next

        while nxt != None:
            
            cur.next = nxt.next
            nxt.next = dummy.next
            dummy.next = nxt
            
            
            nxt = cur.next
            
        return dummy.next