```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        dummy.next = head
        pre = dummy
        cur = dummy.next
        while cur:
            if cur.next and cur.next.val == cur.val:
                tmp = cur.val
                while cur and cur.val == tmp:
                    cur = cur.next
            else:
                pre.next = cur
                pre = cur
                cur = cur.next
        pre.next = cur
        return dummy.next
```

这里添加头指针是本题解题的关键，如果不采用这种办法，后面会有很复杂的逻辑判断。
此外，快慢指针应该都能想到吧，快指针用来过滤重复的元素，慢指针则用来记录重复元素开始的位置。
