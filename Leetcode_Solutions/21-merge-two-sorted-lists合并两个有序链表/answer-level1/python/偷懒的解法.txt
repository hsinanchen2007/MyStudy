### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None:
            return l2
        elif l2 == None:
            return l1
        
        arr = []
        while l1 or l2:
            if l1:
                arr.append(l1.val)
                l1 = l1.next
            if l2:
                arr.append(l2.val)
                l2 = l2.next
        arr.sort()

        head = ListNode(arr[0])
        last = head
        for a in arr[1:]:
            last.next = ListNode(a)
            last = last.next
        return head

            
        
        
```