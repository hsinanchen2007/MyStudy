```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next
```
本来还以为很难的题目，其实代码很简单。
上学的时候老师只教过，删除node需要将node前一个结点指向下下一个结点即可。
这里还挺另类的，node结点如果是一个生命的话，他其实不想离开，所以杀了旁边的一个结点保全自己。