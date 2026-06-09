### 解题思路
链表相关都可以考虑递归。如果当前节点和下一个节点的值相同，则返回第二个节点（相当于删除重复元素的第一个），在每个递归中将下一个递归的结果连接到当前节点。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head:
            head.next = self.deleteDuplicates(head.next)
            if head.next and (head.val == head.next.val):
                return head.next
            else:
                return head

        # 已有大佬简写成：
        #  if head:
        #     head.next = self.deleteDuplicates(head.next)
        #     return head.next if head.next and head.val == head.next.val else head


          

```