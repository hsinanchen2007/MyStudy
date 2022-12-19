### 解题思路
首先特异点排除和测量链表长度。
然后，对k进行化简。
最后，进行旋转即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head is None or head.next is None:
            return head
        l, t = 1, head
        while t.next:
            l, t = l + 1, t.next
        k %= l
        while k > 0:
            temp = head
            while head.next.next:
                head = head.next
            vol, vol.next, head.next = head.next, temp, None
            head, k = vol, k - 1
        return head
```