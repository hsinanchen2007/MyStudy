### 解题思路
打卡打卡

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None:
            return None

        firstNode = head
        nextNode = None
        while(firstNode != None):
            temp = firstNode.next
            firstNode.next = nextNode
            nextNode = firstNode
            firstNode = temp
        return nextNode
            
```