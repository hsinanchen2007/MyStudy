```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        str1 = ""
        str2 = ""
        first = l1
        second = l2
        while first != None:
            str1 += str(first.val)
            first = first.next
        while second != None:
            str2 += str(second.val)
            second = second.next
        str3 = str1[::-1]
        str4 = str2[::-1]
        n1 = int(str3) + int(str4)
        str5 = str(n1)
        str6 = str5[::-1]
        len1 = len(str6)
        l3 = ListNode(0)
        l3.next = l1
        third = l3
        for i in range(len1):
            bb = ListNode(int(str6[i]))
            third.next = bb
            third = third.next
        l3 = l3.next
        return(l3)
```
