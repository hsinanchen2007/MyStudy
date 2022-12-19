### 显示详情
执行用时:
44 ms, 在所有 Python3 提交中击败了 46.06% 的用户
内存消耗: 
13.5 MB, 在所有 Python3 提交中击败了 33.72% 的用户

### 解题思路
参考官方题解，设置一个伪头结点，非常好。
设 l2 往 l1 里面插，即使插在头位置也非常方便。统一了插在链表的头位置，或者中间位置。
我自己写的没有设此，导致首先要判断一下，找 l1 或者 l2 的第一个节点为头结点。代码过于冗余累赘。

查看了最快的人的代码，思路是一样的，但其判断都用了 if A ，并且其冗余更小。
似乎在 python3 中， if A 比 if A!=None 要快上一些。另外，更少的逻辑也许会更快。



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
        prehead = ListNode(-1)
        prev = prehead

        while (l1 != None) and (l2 != None):
            if l1.val <= l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next
            prev = prev.next

        if l1 != None:
            prev.next = l1
        else:
            prev.next = l2
        
        return prehead.next

class Solution:  # 进一步优化的代码
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:

        prehead = ListNode(-1)
        prev = prehead

        while l1 and l2:
            if l1.val <= l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next
            prev = prev.next

        if l1:
            prev.next = l1
        else:
            prev.next = l2
        
        return prehead.next




class Solution:  # 原来的解答， 过于累赘。
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        
        p1, p2 = l1, l2
        if p1.val <= p2.val:
            head = p1
            p1 = p1.next
        else:
            head = p2
            p2 = p2.next
        p = head
        while (p1 != None) and (p2 != None):
            if p1.val <= p2.val:
                p.next = p1
                p1 = p1.next
            else:
                p.next = p2
                p2 = p2.next
            p = p.next
            
        if p1 != None:
            p.next = p1
        else:
            p.next = p2
        return head


```