这题可以用递归，也可以使用一个数组存储每个节点的值，重新生成一个链表。这题其实很简单，while循环就可以解决，我这里就贴出while循环的代码：


```
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        
        second = head.next
        head.next = None
        first = head
        while second:
            third = second.next
            second.next = first
            first = second
            second = third

        return first
```
