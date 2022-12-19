### 解题思路
使用第一个节点保存head值，应对头节点就是要删除的节点的情况

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        temp = ListNode(0)
        temp.next = head
        prev = temp

        while(prev.next != None):
            if (prev.next.val == val):
                prev.next = prev.next.next
            else:
                prev = prev.next
        
        return temp.next
```