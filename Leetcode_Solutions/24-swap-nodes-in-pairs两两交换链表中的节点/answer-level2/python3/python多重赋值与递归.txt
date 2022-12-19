```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        if head.next:
            # print(head.val)
            # print(head.next.val)
            # print(head.next.next.val)
            # python多重赋值，先计算等号右式，再等号左边从左到右赋值            
            head.next.next, head.next, head = head, self.swapPairs(head.next.next), head.next
            # print(head.val)
            # print(head.next.val)
            # print(head.next.next.val)
        
        
        return head    
```
