### 解题思路
此处撰写解题思路
很简单的双指针思路，注意还有剩下的 l1 or l2 节点即可，以及每次的进位 p ，如果有就继续创建节点即可。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)
        p = 0
        cur = head
        while l1 and l2:
            c = (l1.val + l2.val + p)
            p = c//10
            cur.next = ListNode(c%10)
            cur = cur.next
            l1 = l1.next
            l2 = l2.next
        
        l = l1 or l2
        while l:
            c = (l.val + p)
            p = c//10
            cur.next = ListNode(c%10)
            cur = cur.next
            l = l.next
        
        if p:
            cur.next = ListNode(p)            

        return head.next


```