### 解题思路
迭代比较容易想到，按顺序处理每个节点
1. 先保存curr的next
2. 将curr的next指向prev
3. 将prev指向curr
4. 将curr指向之前保存的next

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        curr = head
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return prev

```