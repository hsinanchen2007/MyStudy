### 解题思路
python递归 tail永远指向队尾 不要让链表断掉

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head==None or head.next==None:
            return head
        tail=self.reverseList(head.next)
        head.next.next=head
        head.next=None
        return tail
```