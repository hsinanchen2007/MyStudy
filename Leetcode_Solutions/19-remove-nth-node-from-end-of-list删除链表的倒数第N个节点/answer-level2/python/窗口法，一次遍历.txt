### 解题思路
双指针pre_node和tail_node，跨度为n，保持窗口宽度，右移tail_node，当tail_node为尾结点时，pre_node为要删除的目标结点前驱，删除目标结点，应注意处理目标结点为head的情况。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # y = head
        # while y:
        #     x = y
        #     count = 0
        #     while count < n:        # 找删除点
        #         if x is not None:
        #             x = x.next
        #         else:
        #             break
        #         count += 1
        #     if count < n:   # 输入的数字>链表长度
        #         return head
        #     elif x is None:     # 删除链表头
        #         head = y.next
        #         return head
        #     elif x.next is None:      # 确认是删除点  
        #         y.next = y.next.next
        #         return head
        #     y = y.next
        # return head

        pre_node = ListNode(-1)
        pre_node.next = head

        tail_node = pre_node

        while n > 0:
            tail_node = tail_node.next
            if tail_node is None:
                break
            n -= 1

        # n无效
        if n > 0:
            return head
        # 窗口法查找要删除的目标结点，pre_node为目标结点前驱
        while tail_node.next:
            pre_node = pre_node.next
            tail_node = tail_node.next
        # 处理要删除的结点是head
        if pre_node.next == head:
            head = head.next
            return head
        # 删除目标结点
        else:
            pre_node.next = pre_node.next.next
            return head
```