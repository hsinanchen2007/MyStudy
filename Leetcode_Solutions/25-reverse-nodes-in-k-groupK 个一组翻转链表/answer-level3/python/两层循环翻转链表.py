### 解题思路
先遍历链表得到节点数n，使用两层循环，外侧循环更新上一段的尾节点和新一段的第一个节点，内侧循环功能翻转链表。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        pre = ListNode(1)
        tmp, pre.next, tail, first = head, head, pre, head
        num = 0
        while tmp != None:
            tmp = tmp.next
            num += 1
        for _ in range(num//k): 
            old = first
            new = old.next
            for _ in range(k-1):
                new.next, old, new = old, new, new.next
            tail.next, tail, first = old, first, new
        tail.next = first
        return pre.next
```