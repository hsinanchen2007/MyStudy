- 刚开始理解错了 #return filter(lambda l: l != node, head) 这么去解决问题。
- A -> B -> C, 变成 A -> C。 B是要删除的结点, 让C变成B就好了。


```
"""
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
单向链表 删除一个节点
就是用下一个Node节点, 去替代当前节点
eg: A -> B -> C, 变成 A -> C
B是要删除的结点, 让C变成B就好了
"""

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        # 这个是错的 
        #return filter(lambda l: l != node, head)
        node.value, node.next = node.value.next, node.next.next

# print Solution().deleteNode(5)
```
