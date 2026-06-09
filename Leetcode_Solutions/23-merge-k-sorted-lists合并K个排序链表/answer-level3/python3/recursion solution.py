靓仔，递归方法很简单喔
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        #recursion
        if all([x == None for x in lists]):
            return None
        
        if len(lists) == 1: return lists[0]
        
        head = None
        nodes = [(x.val if x else None) for x in lists]
        if all([x == None for x in nodes]): return None
        M = min([x for x in nodes if x!=None])
        max_idx = [i for i in range(len(nodes)) if nodes[i] == M]
        
        idx = max_idx.pop()
        head = lists[idx]
        lists[idx] = lists[idx].next
        
        curr = head
        while max_idx:
            idx = max_idx.pop()
            curr.next = lists[idx]
            lists[idx] = lists[idx].next
            curr = curr.next

        
        curr.next = self.mergeKLists(lists)
        
        return head
```

计算开销在于几次取最小值，复杂度为O(k*n)