- **解题思路**：利用快慢找到相遇点后，如何确定链表入环的起始节点  ----> 该节点到头结点的距离和到相遇点的距离相等。
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 利用快慢指针求解
        slow = fast = find = head                 
# AttributeError: 'NoneType' object has no attribute 'next'
# 若没有第二个判断语句，当fast访问最后一个节点（无环）的.next.next时就相当于访问了None.next!会报上面的错误！
        while fast and fast.next: 
            slow = slow.next           
            fast = fast.next.next
            if slow == fast:
                while find!= fast:
                    find = find.next
                    fast = fast.next
                return find
        return None
```
