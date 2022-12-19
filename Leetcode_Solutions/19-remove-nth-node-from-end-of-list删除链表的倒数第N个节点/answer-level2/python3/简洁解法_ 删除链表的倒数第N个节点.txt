# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        from collections import deque
        queue = deque(maxlen=n+1)
        queue.append(head)
        tmp_head = head.next
        while tmp_head:
            queue.append(tmp_head)
            tmp_head = tmp_head.next
        if n == 1:  # 删除尾节点
            if len(queue) == 1:
                return None
            else:
                queue[-2].next = None
        elif n == len(queue):   #删除头节点
            head = queue[1]
        else:
            queue[-n-1].next = queue[-n+1]
        return head
                