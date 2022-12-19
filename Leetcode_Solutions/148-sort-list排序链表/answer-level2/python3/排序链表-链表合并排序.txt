### 解题思路-合并排序；
1. 将链表从中间分开生成两个链表`head1, head2`（利用快慢指针）；分别对这两个链表排序；再将排好序的链表合并成一个链表；
2. 排序主要是通过递归的方法两两合并从而排好序；

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    """
    O(nlogn)时间复杂度—>链表合并排序
    """
    def merge(self, head1, head2):
        """
        head1, head2分别为排序好的两个链表
        merge()用来将head1, head2合并返回新的排序链表
        """
        prehead = ListNode(0)
        pre = prehead
        while head1 and head2:
            if head1.val <= head2.val:
                pre.next = head1
                head1 = head1.next
            else:
                pre.next = head2
                head2 = head2.next
            pre = pre.next
        
        if not head1:
            pre.next = head2
        else:
            pre.next = head1
        
        return prehead.next

    def sortList(self, head: ListNode) -> ListNode:
        # head为None或只有一个节点时，表明当前链表为排序好的链表；直接返回
        if not (head and head.next):
            return head
        
        # 快慢指针将head链表划分成两半； 
        slow, fast = head, head.next
        fast = fast.next if fast else None
        while slow and fast:
            slow = slow.next
            fast = fast.next
            fast = fast.next if fast else None
        # 两个链表分别为head, head2; 
        head2, slow.next = slow.next, None
        # 递归合并排序
        head = self.sortList(head)
        head2 = self.sortList(head2)
        return self.merge(head, head2)

```