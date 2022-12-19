### 解题思路
利用栈先进后出的特性，列表模拟栈

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        if head == None or k == 0:
            return None
        list = []
        while head != None:
            list.append(head)
            head = head.next
        
        index = 0
        temp = None
        while list:
            index += 1
            temp = list.pop()
            if index == k:
                break
        return temp
```