### 解题思路
链表闭合成环，然后找到合适的位置切开 
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head is None:
            return head
        size = 1
        curNode = head

        while curNode.next is not None:
            curNode = curNode.next
            size += 1
        
        curNode.next = head   # 将单向列表合并成环
        step = k%size
        curNode = curNode.next
        
        j = 1
        while j < size - step:
            curNode = curNode.next
            j += 1
        
        newHead = curNode.next
        curNode.next = None
        

        return newHead
```