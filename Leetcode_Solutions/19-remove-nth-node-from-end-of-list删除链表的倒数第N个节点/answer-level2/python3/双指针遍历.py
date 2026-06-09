### 解题思路
哑结点防止删除的是头结点导致无法返回结果，
双指针遍历：first一开始指向哑结点，last指向第n个节点，然后同时后移动，直到last移动到尾结点，此时first在倒数第n个节点的前置节点，
然后first.next=first.next.next移除目标节点返回哑结点的下一个节点即可
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        first=thead=ListNode(0)
        thead.next=head
        last=head
        count=1
        while count!=n:
            last=last.next
            count+=1
        while last.next:
            first=first.next
            last=last.next
        first.next=first.next.next
        return thead.next
        
        
```