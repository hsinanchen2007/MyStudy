### 解题思路
思路很简单，就是重点要注意先检查头节点是否为我们要删除的目标节点。
删除完头节点后，令node等于head，遍历node的下一个节点：
如果是我们要删除的值就按照单链表删除节点的方式操作就好，但删完之后先不要移动node，因为node.next已经变了，要重新判断；
如果不是我们要删除的目标节点才能移动node，直到node.next为空。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if not head: return 
        node = head
        while head and node:
            if head.val == val:
                head = head.next
                node = head
                continue
            if not node.next: return head
            if node.next.val == val:
                node.next = node.next.next
            else: node = node.next
        return head
```