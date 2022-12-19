### 解题思路
增加一个虚拟头结点便于在头部删去节点，或者在头部插入节点，
便于合并两个有序链表。



### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        prehead = ListNode(-1)  # 虚拟头节点，方便在开始位置删去
        prehead.next = head
        prev, p = prehead, head
        while p!= None:
            if p.val == val:
                prev.next = p.next
                del p
                break  #题目保证链表中节点的值互不相同
            p = p.next
            prev = prev.next

        return prehead.next
```