### 解题思路
增加头结点使判断趋于一致

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        pre, cur = head, head.next
        headNode = ListNode(float('-inf')) # 头结点
        headNode.next = head
        while cur:
            if cur.val >= pre.val:
                pre, cur = pre.next, cur.next
                continue
            node = headNode
            while node.next.val < cur.val: # 从前往后寻找第一个插入位置
                node = node.next
            pre.next = cur.next
            cur.next = node.next
            node.next = cur

            cur = pre.next
        return headNode.next

```