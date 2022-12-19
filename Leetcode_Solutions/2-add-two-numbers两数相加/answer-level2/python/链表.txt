### 解题思路
先把链表存储成list，然后list倒序，然后两个list相加，然后再把相加的结果存储成链表返回。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        list1 = []
        list2 = []
        p = l1
        p2 = l2
        while p is not None:
            list1.append(str(p.val))
            p = p.next
        while p2 is not None:
            list2.append(str(p2.val))
            p2 = p2.next
        list1.reverse()
        list2.reverse()
        st1 =int( ''.join(list1))
        st2 =int( ''.join(list2))

        list3 = []
        for i in str(st1+st2):
            list3.append(i)
        list3.reverse()
        head = ListNode(list3[0])
        p = head
        for i in range(1,len(list3)):
            p.next = ListNode(list3[i])
            p = p.next
            
        return head
```