```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists:
            return []
        def sortm(head1, head2):
            tmp_node = ListNode(0)
            tmp_point = tmp_node
            while head1 and head2:
                if head1.val < head2.val:
                    tmp_point.next = head1
                    head1 = head1.next
                elif head1.val >= head2.val:
                    tmp_point.next = head2
                    head2 = head2.next
                tmp_point = tmp_point.next
            if head1:
                tmp_point.next = head1
            if head2:
                tmp_point.next = head2
            return tmp_node.next
        
        while len(lists) > 1:
            i = 0
            lists2 = []
            while i < len(lists):
                if i + 1 < len(lists):
                    lists2.append(sortm(lists[i],lists[i+1]))
                else:
                    lists2.append(lists[i])
                i += 2
            lists = lists2
        return lists[0]
```