### 解题思路
注意特殊情况，链表为空或者链表只有一个结点。注意特别处理首尾结点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:return head
        pre,pcur = head, head.next
        while pcur is not None:
            tmp = pcur.next
            pcur.next = pre
            pre = pcur
            pcur = tmp
        dummy = ListNode(0)
        dummy.next = pre
        head.next = None
        return dummy.next
```