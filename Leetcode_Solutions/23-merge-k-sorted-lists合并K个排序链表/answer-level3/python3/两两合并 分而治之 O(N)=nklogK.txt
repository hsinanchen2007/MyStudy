```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if len(lists) == 0: return
        if len(lists) == 1: return lists[0]
        if len(lists) == 2:
            dummyhead = ListNode()
            root = ListNode()
            dummyhead = root
            h1,h2 = lists[0],lists[1]
            while h1 and h2:
                if h1.val<h2.val:
                    root.next = h1
                    h1 = h1.next
                else:
                    root.next = h2
                    h2 = h2.next
                root = root.next
            if h1:
                root.next = h1
            if h2:
                root.next = h2
            return dummyhead.next

        mid = len(lists)//2
        return self.mergeKLists([self.mergeKLists(lists[:mid]), self.mergeKLists(lists[mid:])])
        
```
