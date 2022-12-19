
```
class Solution:
    def __init__(self):
        self.tmp = []

    def px(self, listb):
        if listb.next:
            self.tmp.append(listb.val)
            self.px(listb.next)
        else:
            self.tmp.append(listb.val)
            return

    def zh(self, last):
        if self.tmp:
            l = ListNode(self.tmp.pop())
            if self.tmp:
                self.zh(l)
            last.next = l

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not any([True if p else False for p in lists]):
            return []

        for p in lists:
            if p:
                self.px(p)

        self.tmp = sorted(self.tmp, reverse=True)
        
        # 生成新的链表
        d = ListNode(self.tmp.pop())
        self.zh(d)
        return d
```
