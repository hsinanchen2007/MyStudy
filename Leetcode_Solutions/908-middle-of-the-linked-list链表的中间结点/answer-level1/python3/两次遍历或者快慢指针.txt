### 解题思路
简单题，两次遍历，一次先得到长度，第二次再取值
或者用快慢指针来做

很迷的是，两种方法的运行时间和内存消耗和我预期的并不太一样，可能这就是python吧。。。。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
#  顺序遍历
#         cur = head
#         length = 0
#         while(cur):
#             length += 1
#             cur = cur.next
        
#         if length%2 == 0:
#             mid = length/2 + 1
#         else:
#             mid = math.ceil(length / 2)
#         mid -= 1
#         cur = head
#         while(mid):
#             cur = cur.next
#             mid -= 1
        
#         return cur 

#  快慢指针
        fast, slow = head, head
        while(fast and fast.next):
            fast = fast.next.next
            slow = slow.next
        
        return slow

```