### 解题思路
此处撰写解题思路
画图/伪代码
1）迭代，稍显麻烦，跟官方版本一致
2）查看别人代码，发现python可以用一句话赋值多个变量，神奇！
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
        
        Node_last = None
        while head:
            head.next,Node_last,head = Node_last,head,head.next
        return Node_last

        
        
```