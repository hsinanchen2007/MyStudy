```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        str1 = ""
        while head != None:
            str1 += str(head.val)
            head = head.next
        n1 = len(str1)
        num = 0
        if str1 == "0":
            return(0)
        for i in str1:
            n3 = int(i)
            if n3 == 0:
                pass
            else:
                n2 = (n3 * 2) ** (n1-1) 
                num += n2
            n1 -= 1
        return(num)
        
```
