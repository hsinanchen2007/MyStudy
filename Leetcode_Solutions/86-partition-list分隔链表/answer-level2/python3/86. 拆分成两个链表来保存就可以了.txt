### 解题思路
拆成两个链表分别保存小于x和大于等于x的节点。
在开始建立新的链表记得设置：小于x的链表头以及指针，大于等于x的链表头以及指针。
最开始的时候没有固定链表头结点，写到最后的时候发现指针已经移到最后，没法返回链表了。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        less = less_head = ListNode(0)
        more = more_head = ListNode(0)

        while head:
            if head.val < x:
                less.next = head
                less = less.next
            else:
                more.next = head
                more = more.next
            
            head = head.next
        more.next = None

        less.next = more_head.next

        return less_head.next
        
```