```
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        res = []
        for i in lists:
            while i:
                res.append(i.val)
                i = i.next
        if res == []:
            return []
        res.sort()
        return res
```