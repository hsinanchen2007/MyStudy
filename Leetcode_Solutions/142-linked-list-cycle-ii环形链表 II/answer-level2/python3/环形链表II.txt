### 解题思路
利用快慢指针，快指针fast每次走两步，慢指针slow每次走一步。
1.fast走到链表末，返回None；
2.当fast=slow，两指针第一次相遇，slow指针从相遇位置出发，p指针从最开始位置出发，相遇的位置即为环入口
   {a = 从开始位置到环入口的步数；
     b = 一环的步数。}
fast和slow第一次相遇后，之后fast一定比slow多走n圈———fast = slow + nb
而fast = 2 * slow    联立两式可得slow = nb

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return None
        fast, slow = head, head
        while True:
            if fast is None or fast.next is None:
                return
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                break
        
        p = head
        while p != slow:
            p = p.next
            slow = slow.next
        return p
            
        


```