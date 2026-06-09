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
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        '''由于两个链表是排好序的,所以相当与最后一次的归并排序'''
        cur1 = l1
        cur2 = l2
        head = ListNode(0)
        res = head
        while cur1 and cur2:
            if cur1.val <= cur2.val:
                res.next = ListNode(cur1.val)
                res = res.next                                  
                cur1 = cur1.next
            else:
                res.next = ListNode(cur2.val)
                res = res.next
                cur2 = cur2.next
        # res.next = cur1 if cur1 else cur2(如果归并后l1或者l2还有剩直接接入到res中)
        if cur1:  
            res.next = cur1
        elif cur2:
            res.next = cur2
        return head.next
```