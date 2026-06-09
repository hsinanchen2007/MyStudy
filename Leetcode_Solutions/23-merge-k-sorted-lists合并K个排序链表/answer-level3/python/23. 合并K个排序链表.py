### 解题思路
先写一个两两合并的函数；
从`lists`中pop两个链表进行合并，将结果append到`lists`中；
直到`lists`的数量为1

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def merge2Lists(self, l1, l2):
        res = head = ListNode(-1)
        while l1 and l2:
            if l1.val <= l2.val:
                head.next = l1
                l1 = l1.next
            else:
                head.next = l2
                l2 = l2.next
            head = head.next
        if l1:
            head.next = l1
        if l2:
            head.next = l2
        return res.next
        
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if len(lists) == 0:
            return None
        while len(lists) != 1:
            l1 = lists.pop(0)
            l2 = lists.pop(0)
            res = self.merge2Lists(l1, l2)
            lists.append(res)
        return lists[0]


```