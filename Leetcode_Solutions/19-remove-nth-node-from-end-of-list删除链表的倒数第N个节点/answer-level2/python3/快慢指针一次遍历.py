**思路**
一次遍历完成双指针法
1. 设想删除倒数第二个节点，设定快慢指针，快指针比慢指针遍历节点快n个节点
2. 当快指针遍历到尾节点时，慢指针的下一个节点就是需要删除的节点

```
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
        dummy = ListNode(0)
        dummy.next = head

        slow, fast = dummy, dummy
        count = 0
        while fast and fast.next:
            if count < n:
                fast = fast.next
                count += 1
            else:
                slow = slow.next
                fast = fast.next

        slow.next = slow.next.next
        return dummy.next
```