### 解题思路
此处撰写解题思路
迭代的第一步，可以理解为先在dummy后面插入head,之后再在dummy与head之间插入head.next.
具体如图：
![image.png](https://pic.leetcode-cn.com/890d32d81ff8128d136f49e2bc9908a0a3ddff147dbbd9ddfe40d089004dcccb-image.png)

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

        dummy = ListNode(None)
        while head:
           nxt = head.next
           head.next = dummy.next
           dummy.next = head
           head = nxt
        return dummy.next

        # recursion
        # if head is None or head.next is None:
        #     return head
        # cur = self.reverseList(head.next)
        # head.next.next = head
        # head.next = None
        # return cur
```