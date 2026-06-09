### 解题思路
和两两翻转一样的思路，但是这种效果并不好，额外空间是k，勉强能算，也可以说是不算
还是递归靠谱一点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        node=ListNode(0)
        node.next=head
        first,second=node.next,node
        while first:
            buf=[first]
            for i in range(k-1): 
                first=first.next
                buf.append(first)
                if not first: return node.next
            first=first.next
            for i in buf[::-1]:
                second.next=i
                second=second.next
            second.next=first
        return node.next
```