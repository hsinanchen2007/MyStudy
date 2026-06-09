class Solution:

    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head == None:
            return head
        
        
        elif head.next == None and head.val == val:
            return None
        
        dummy = ListNode(0)
        dummy.next = head
        
        pre = dummy
        cur = head
        
        
        while cur !=None:
            if cur.val == val:
                pre.next = cur.next
                cur = cur.next
                continue
            pre = cur
            cur = cur.next
            
        
        
        return dummy.next