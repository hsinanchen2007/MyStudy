### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        array = []
        reverse = ListNode(None)
        reverse_head = reverse
        if head == None:
            return head
        while head != None:
            array.append(head.val)
            head = head.next
        for i in range(0,len(array)):
            reverse_head.val = array[len(array)-i-1]
            if i != len(array)-1:
                reverse_head.next = ListNode(None)
                reverse_head = reverse_head.next
        head = reverse
        return head
```