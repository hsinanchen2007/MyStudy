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
    def swapPairs(self, head: ListNode) -> ListNode:
        pre=ListNode(None)
        pre.next=head
        cur=pre
        while cur.next and cur.next.next:
            a,b=cur.next,cur.next.next
            a.next=b.next
            b.next=a
            cur.next=b
            cur=cur.next.next
        return pre.next

```