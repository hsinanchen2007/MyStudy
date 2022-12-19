时间复杂度O(n)
空间复杂度O(n)
`
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        
        a = []
        
        while head:
            a.append(head)
            head = head.next
   
        if n == len(a):
            new = a[0].next
            a[0].next = None
            return new
        if n == 1:
            a[-2].next = None
            return a[0]
        
        a[-n-1].next = a[-n+1]
        return a[0]
`