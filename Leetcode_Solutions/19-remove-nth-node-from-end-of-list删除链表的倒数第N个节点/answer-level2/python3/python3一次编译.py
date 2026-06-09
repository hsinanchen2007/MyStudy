### 解题思路
此处撰写解题思路

### 代码
这是一次遍历的：
1.如果输入的只有一个数的链表，直接返回空链表
2.如果又若干数的链表：
    i.  n=1时，直接删除最后一个节点
    ii. i!=1时：
            如果是删除第一个节点直接删除；
            否则，找到第n个节点l2后，用l3记住l1(头节点)，l1与l3一同往后遍历，直到l2.next为空；
            删除l1节点；
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        l1 = head
        if  l1.next != None :
            if n == 1:
                while l1.next != None:
                    l2 = l1
                    l1 = l1.next
                l2.next = None
                return head
            else: 
                while n != 0:
                    l2 = l1
                    l1 = l1.next
                    n = n -1
        else:  
            return None
        l1 = head
        if l2.next != None:
            while l2.next != None:
                l3 = l1
                l1 = l1.next
                l2 = l2.next
            l3.next = l1.next
        else:
            head = head.next
        return head
```