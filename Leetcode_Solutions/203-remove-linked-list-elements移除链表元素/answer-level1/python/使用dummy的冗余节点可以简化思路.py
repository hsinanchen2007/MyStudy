### 解题思路
使用dummpy节点，本身为空，这个节点简化思路

### 代码

```python
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        dummpy_node = ListNode(None)
        curr = dummpy_node
        while head:
            if head.val != val:
                curr.next = head
                curr = curr.next
            head = head.next
        curr.next = None
        return dummpy_node.next


```