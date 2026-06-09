### 解题思路
遍历整个链表，计算长度，将链表指针后移长度的一半

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        tem = head
        num = 0
        while(head is not None):
            num += 1
            head = head.next
        index = num//2
        while index>0:
            index -=1
            tem = tem.next

        return tem

```