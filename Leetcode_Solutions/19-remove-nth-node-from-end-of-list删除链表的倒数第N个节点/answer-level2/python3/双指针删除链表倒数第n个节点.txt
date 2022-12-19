### 解题思路
注意 删除头节点的情况
注意 需要找到删除节点的前一个节点
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # eg [5,4,3,2,1]
        node = head
        while n>0:
            node = node.next
            n -= 1
        # 若头节点就是需要删除的倒数第n和节点
        if not node:
            return head.next
        else:
            # 此时，head是倒数第n+1个节点（设node为倒数第一个节点）
            ans = head
            # 遍历直到node为最后一个节点（而不是末尾空指针）
            while node.next:
                node, ans = node.next, ans.next
            # 删除ans的下个节点
            ans.next = ans.next.next
            return head
```
双指针删除链表倒数第n个节点
