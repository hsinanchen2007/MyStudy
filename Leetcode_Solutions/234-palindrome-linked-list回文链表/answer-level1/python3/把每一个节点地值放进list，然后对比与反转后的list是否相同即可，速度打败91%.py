class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        
        
        l= []
        
        while head != None:
            
                
            l.append(head.val)
            head = head.next
            
        
        
        return l == l[::-1]