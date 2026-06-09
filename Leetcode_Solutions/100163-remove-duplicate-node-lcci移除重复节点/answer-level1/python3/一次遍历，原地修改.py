### 解题思路
此处撰写解题思路
首先检查是不是空链表，若是，则直接返回
用一个集合记录哪些节点出现过，头节点的节点一定是第一次出现，所以保留
往后遍历，若节点出现过，则删除，否则加入集合，然后往后走
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head:
            return head
        my_set={head.val}
        ret=head
        while head.next:
            if head.next.val in my_set:
                head.next=head.next.next
            else:
                my_set.add(head.next.val)
                head=head.next 
        return ret      
```