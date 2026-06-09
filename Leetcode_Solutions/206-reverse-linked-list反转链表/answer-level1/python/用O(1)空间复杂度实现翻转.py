### 解题思路
1.首先创立的一个空node,
2.用一个指针在原链表上滑动。
3.每滑动到一个新节点，将新节点插入到第1步创立的node后面

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        res = ListNode(-1)
        while head:
            temp = head
            head = head.next
            temp.next = None
            temp.next = res.next
            res.next = temp
        return res.next
```