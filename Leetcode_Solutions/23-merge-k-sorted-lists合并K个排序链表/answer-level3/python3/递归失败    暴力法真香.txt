### 解题思路
买了否冷

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        # ind = 0
        # temp = ListNode(float("inf"))
        # i = 0
        # while i < len(lists):
        #     if lists[i] is None:
        #         del lists[i]
        #         continue
        #     else:
        #         if lists[i].val < temp.val:
        #             ind = i
        #             temp = lists[i]
        #         i += 1
        # if not lists:
        #     return None
        # if lists[ind].next:
        #     lists[ind] = lists[ind].next
        # else:
        #     del lists[ind]
        # temp.next = self.mergeKLists(lists)
        # return temp

        self.nodes = []
        head = point = ListNode(0)
        for l in lists:
            while l:
                self.nodes.append(l.val)
                l = l.next
        for x in sorted(self.nodes):
            point.next = ListNode(x)
            point = point.next
        return head.next

        

            
```