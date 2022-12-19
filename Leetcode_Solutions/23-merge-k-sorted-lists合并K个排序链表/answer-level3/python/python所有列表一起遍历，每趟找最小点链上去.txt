```

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        dummyHead = ListNode(-1)
        cur = dummyHead
        l = [x for x in lists]
        while True:
            if self.empty(l):
                break
            minIndex = self.minest(l)
            cur.next = l[minIndex]
            cur = cur.next
            l[minIndex] = l[minIndex].next
        return dummyHead.next

    def minest(self,lists):
        import sys
        min = sys.maxint
        min_index = -1
        for i,x in enumerate(lists):
            if x is None:
                continue
            else:
                if x.val < min:
                    min = x.val
                    min_index = i
        return min_index

    def empty(self, lists):
        for x in lists:
            if x is not None:
                return False
        return True
```
