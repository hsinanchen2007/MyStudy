### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        """
        1.找中点，分两段
        2.对两段分别执行排序合并
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        slowPoint = head
        fastPoint = head
        while fastPoint.next is not None and fastPoint.next.next is not None:
            slowPoint = slowPoint.next
            fastPoint = fastPoint.next.next
        head2 = slowPoint.next
        slowPoint.next = None
        # 自此分成两段
        lnode = self.sortList(head)
        rnode = self.sortList(head2)

        return self.__merge_two_sorted_listNode(lnode, rnode)
        
    def __merge_two_sorted_listNode(self, head1, head2):
        if head1 is None:
            return head2
        if head2 is None:
            return head1

        if head1.val < head2.val:
            head1.next = self.__merge_two_sorted_listNode(head1.next, head2)
            return head1
        else:
            head2.next = self.__merge_two_sorted_listNode(head1, head2.next)
            return head2
```