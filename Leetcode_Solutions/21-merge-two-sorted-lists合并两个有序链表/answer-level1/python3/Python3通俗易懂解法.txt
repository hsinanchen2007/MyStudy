### 解题思路
这道题应该算是比较常见的链表基础题, 考点应该还是做好链表的迭代循环处理.
注意一下这里开头的结点没真正存数据, 所以return的时候要return p3.next

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 真正面试的时候要做好特殊case处理
        if l1 is None:
            return l2
        if l2 is None: 
            return l1

        l3 = ListNode(0)
        p = l3
        
        while l1 and l2:
            p.next = ListNode(0)
            p = p.next

            if l1.val <= l2.val:
                p.val = l1.val
                l1 = l1.next
            else:
                p.val = l2.val
                l2 = l2.next
            
        if l1:
            p.next = l1
        else:
            p.next = l2
        
        return l3.next
            
            
```