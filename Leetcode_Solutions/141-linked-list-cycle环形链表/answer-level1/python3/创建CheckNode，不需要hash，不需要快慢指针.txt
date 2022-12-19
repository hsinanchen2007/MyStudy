#首先创建一个checkNode。遍历链表，将访问过的结点的next指向checkNode，
#如果存在环，有节点node1被访问过，则再次访问node1时，node1.next 为checkNode。
#如果没有环，则永远访问不到checkNode。
时间复杂度O(n),空间复杂度O(1),
这种方式会破坏链表结构，如果不在意这一点这个方法会很快

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None



#首先创建一个checkNode。遍历链表，将访问过的结点的next指向checkNode，
#如果存在环，有节点node1被访问过，则再次访问node1时，node1.next 为checkNode。
#如果没有环，则永远访问不到checkNode。

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None:
            return False
        if head.next is None:
            return False
        
        CheckNode = ListNode(-1)
        
        
        while head:
            if head.next is CheckNode:
                return True
            new_head = head.next
            head.next = CheckNode
            head = new_head
        return False
        
```