### 解题思路
递归思路比较简单，
非递归，使用pre保存前几个节点，最后保存尾结点返回

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
        # 递归
        def helper(head):
            if not head or not head.next:
                return head
            node = helper(head.next)
            node.next.next = node
            node.next = None
            return node
        # 非递归
        def reverese(head):
            res = None
            pre = None
            cur = head
            res = None
            while cur:
                tmp = cur.next
                if not tmp:
                    res = cur
                cur.next = pre
                pre = cur
                cur =tmp              
            return pre
        return reverese(head)
```