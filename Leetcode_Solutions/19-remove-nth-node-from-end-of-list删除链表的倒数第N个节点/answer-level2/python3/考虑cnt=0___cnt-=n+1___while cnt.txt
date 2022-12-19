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
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        node=head
        cnt=0
        while node:
            cnt+=1
            node=node.next
        cnt-=n+1
        node=head
        if cnt==-1:
            head=head.next
            return head
        else:
            while cnt:
                node=node.next
                cnt-=1
            node.next=node.next.next
            return head



```