### 解题思路
因为是旋转链表，所以可以把链表结成环处理
首先求链表长，可以将k取余避免重复计算
接着就是旋转，正着转和反着转是有公式对应的

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        l = 1
        temp = head
        while temp.next:
            temp = temp.next
            l += 1
        temp.next = head
        k = k%l
        pre = now = head
        now = now.next
        for _ in range(l-k-1):
            now = now.next
            pre = pre.next
        pre.next = None
        return now



```