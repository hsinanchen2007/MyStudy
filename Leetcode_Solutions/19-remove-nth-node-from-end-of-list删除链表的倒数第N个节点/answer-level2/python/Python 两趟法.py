第一次发题解。感谢各位前辈在其他题目中的题解。
两边扫描，第一遍拿到删除点位置，第二遍找到删除点进行删除。

准备找个暑期实习，默默刷题中...


```python []
# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        node_no = 0
        node = head
        while node is not None:
            node = node.next
            node_no += 1
        node_no -= n + 1

        node = head
        if node_no == -1:
            head = head.next
        else:
            while(node_no):
                node = node.next
                node_no -= 1
            node.next = node.next.next
        return head


# @lc code=end
```