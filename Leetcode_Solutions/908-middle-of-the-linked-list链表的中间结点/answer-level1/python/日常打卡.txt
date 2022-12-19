### 解题思路
Python None

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if not head:
            return head
        temp = head
        num = 0
        print(temp.val)
        while temp != None:
            temp = temp.next
            num += 1

        print(num)

        index = num // 2

        while index > 0:
            index -= 1
            head = head.next
            
        
        return head
```