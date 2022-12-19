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
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head
        p=head
        count=0
        while p:
            count+=1
            p=p.next
        k=k%count
        if k==0:
            return head
        pre,cur=head,head
        for i in range(k):
            cur=cur.next
        while cur.next:
            pre=pre.next
            cur=cur.next
        tmp=pre.next
        pre.next=None
        cur.next=head
        return tmp


```