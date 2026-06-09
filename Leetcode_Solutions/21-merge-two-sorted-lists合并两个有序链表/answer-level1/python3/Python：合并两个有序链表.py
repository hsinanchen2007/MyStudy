### 解题思路
标准递归或者迭代，没想到新颖的算法
迭代双指针还是清楚一点，而且各种变体几乎没有优化
递归使用and or会简单一点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode: 
        l3=ListNode(0)
        l4=l3
        while l1 and l2:
            if l1.val<=l2.val:
                l3.next=l1  
                l1=l1.next
            else:
                l3.next=l2
                l2=l2.next
            l3=l3.next 
        if l1 is None:
            l3.next=l2
        else:
            l3.next=l1   
        l4=l4.next
        return l4  

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 and l2:
            if l1.val > l2.val: l1, l2 = l2, l1
            l1.next = self.mergeTwoLists(l1.next, l2)
        return l1 or l2              
```