### 解题思路


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return 
        if k == 0:
            return head
        dumpy = ListNode(0)

        fast = head
        slow = head 
        ptr = head
        dumpy.next = head
        N = 0

        while dumpy.next:
            dumpy = dumpy.next
            N+=1

        for i in range(k%N):
            fast = fast.next
            
        while fast.next:
            fast = fast.next
            slow = slow.next
            
        fast.next = head
        head = slow.next
        slow.next = None
        
        return head












```