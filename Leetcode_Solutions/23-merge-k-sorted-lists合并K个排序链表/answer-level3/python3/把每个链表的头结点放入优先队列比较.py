```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        import heapq
        l=[]
        for index in range(len(lists)):
            if lists[index]:
                heapq.heappush(l,(lists[index].val,index))
        head=ListNode(-1)
        t=head
        while l:
            a,index=heapq.heappop(l)
            t.next=lists[index]
            t=t.next
            if lists[index].next:
                heapq.heappush(l, (lists[index].next.val, index))
                lists[index]=lists[index].next
        return head.next
```
