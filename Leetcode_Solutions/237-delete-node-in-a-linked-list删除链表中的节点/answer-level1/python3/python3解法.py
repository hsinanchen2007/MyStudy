# 分析
由于题目中只给出一个节点，并且因为这是个单链表，所以无法访问它的上一个节点，也就无法调整上个节点的 next 指针指向。但是我们可以换个思路：通过 node 节点，我们可以访问它的下个节点 next，删除 node，可以通过将 next 的值 val 拷贝给 node，然后调整 node 的指针指向 next 的下一个节点。

# 代码实现
```
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

        # 如果没有题目中的假设条件，那么应该做些异常检测
        """
        if node.next == None:
            node.val = None
            node.next = None
        else:
            node.val = node.next.val
            node.next = node.next.next
        """
```
