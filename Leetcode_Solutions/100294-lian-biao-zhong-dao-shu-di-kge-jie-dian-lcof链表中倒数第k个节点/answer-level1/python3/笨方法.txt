### 解题思路
先求链表长度，获得倒数的位置（链表长度-k），移动头节点位置。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        node = head
        length = 1
        # 计算链表长度
        while node.next != None:
            node = node.next
            length += 1
        # 求倒数下标
        k = length - k
        # 移动头节点
        for i in range(k):
            head = head.next
        # 返回链表
        return head
```