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
    def middleNode(self, head: ListNode) -> ListNode:
        count = 0
        tmp = head
        head = head.next
        while head:
            count+=1
            head = head.next
        half = math.ceil(count/2)
        while half:
            half-=1
            tmp = tmp.next
        return tmp


```