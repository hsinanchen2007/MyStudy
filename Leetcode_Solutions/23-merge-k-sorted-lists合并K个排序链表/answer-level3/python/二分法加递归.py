### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def mergeKLists(self, lists):
        if not lists:
            return None
        return self.merge(lists)

    def merge(self, lists):
        if len(lists) == 1:
            return lists[0]
        mid = len(lists) // 2
        l1 = self.merge(lists[:mid])
        l2 = self.merge(lists[mid:])
        return self.mergeTwoLists(l1, l2)

    def mergeTwoLists(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
```