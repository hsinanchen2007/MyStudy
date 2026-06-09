### 解题思路
此处撰写解题思路
建一个dummy头节点，开始交换，三个指针来操作。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        slow = head
        # fast = head.next
        dummy = ListNode(0)
        dummy.next = head
        cur = dummy

        while slow and slow.next:
            fast = slow.next
            cur.next = fast
            slow.next = fast.next
            fast.next = slow
            cur = slow
            slow = slow.next
            # fast = slow.next  # 偶数个的时候就报错，会碰到slow为None
        return dummy.next



```