一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
新开个链表，按大小存储即可

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, pHead1, pHead2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        res = ListNode(0)
        head = res
        while pHead1 and pHead2:
            if pHead1.val <= pHead2.val:
                head.next = pHead1
                head = head.next
                pHead1 = pHead1.next
            else:
                head.next = pHead2
                head = head.next
                pHead2 = pHead2.next
                
        if pHead1:
            head.next = pHead1
        if pHead2:
            head.next = pHead2
        return res.next
```