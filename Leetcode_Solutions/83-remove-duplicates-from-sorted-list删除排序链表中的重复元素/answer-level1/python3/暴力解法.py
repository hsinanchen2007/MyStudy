### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # 链表题
        # 第一个元素为head
        target = ""
        visit = head
        pre = ListNode(0)
        pre.next = head
        while visit != None:
            # 由head开始 target = head.val
            if visit.val != target:
                target = visit.val
                visit = visit.next
                pre = pre.next
            else:
                # 删除掉一个节点pre-> -> visit.next
                pre.next = visit.next
                visit = visit.next
        return head

                
```