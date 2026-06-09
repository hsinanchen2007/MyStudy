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
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        p = head
//如果为空链表或只有一个节点，则直接返回
        if p is None or p.next is None:
            return head
        checks = [p.val]
        while p is not None and p.next is not None:
//如果p的下一个节点重复，那么直接跳过下一个节点，直到找到不重复的为止或找到空为止
            if p.next.val in checks:
                p.next = p.next.next
                continue
            else:
                checks.append(p.next.val)
                p = p.next
        return head
       
```