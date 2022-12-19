### 解题思路
利用一个栈，两次循环,实现链表反转

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
        #利用一个栈，两次循环,实现链表反转
        #执行用时 :12 ms   内存消耗 :14.7 MB
        
        if not head : return head
        stack = []
        while head :
            stack.append(head)
            head = head.next
        h = stack.pop()
        p = h 
        while stack :
            h.next = stack.pop()
            h = h.next
        h.next = None
        return p
        
```