class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        
        value = []
        while head:
            value.append(head.val)
            head = head.next
         
        return value[::-1] == value



class Solution:
    def isPalindrome(self, head: ListNode) -> bool:

        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            
        prev = None
        curr = slow
        while curr:
            nextTemp = curr.next
            curr.next = prev
            prev = curr
            curr = nextTemp
            
        while prev and head:
            if prev.val != head.val:
                return False
            prev = prev.next
            head = head.next
        return True