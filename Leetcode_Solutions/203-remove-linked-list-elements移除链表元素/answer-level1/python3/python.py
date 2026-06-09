### 解题思路
记录当前节点与当前节点的父节点，当当前节点为待删除元素时，跳过该元素。若不是当前元素，父节点与子节点同时向右移动一位

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy=ListNode(-1)

        dummy.next=head
        pre=dummy
        cur=head
        while cur:
            if cur.val==val:
                pre.next=cur.next
                cur=cur.next
            else:
                pre=pre.next
                cur=cur.next
        return   dummy.next


     
```