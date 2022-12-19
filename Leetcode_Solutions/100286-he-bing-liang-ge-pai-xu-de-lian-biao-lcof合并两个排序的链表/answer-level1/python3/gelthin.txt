### 解题思路
与主站 [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)
查看其对应的题解 [gelthin-设置伪头结点+if A 比 if A!=None 快](https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/gelthin-she-zhi-wei-tou-jie-dian-by-gelthin/)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None:
            return l2
        if l2 == None:
            return l1

        prehead = ListNode(-1)  # 构造一个伪头结点，避免头部插入的冗余代码
        p = prehead
        while (l1 != None) and (l2 != None):
            if l1.val <= l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next
        if l1 != None:
            p.next = l1
        if l2 != None:
            p.next = l2

        return prehead.next

```