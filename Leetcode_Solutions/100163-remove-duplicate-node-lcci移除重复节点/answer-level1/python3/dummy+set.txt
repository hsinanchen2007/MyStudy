### 解题思路
method1: dummy+set
method2: sort+inplace(over engineering)
method3: n^2一个i，循环整个list，另一个from i->end: find(i),然后除掉i

### 代码

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head:
            return head
        dic = set()
        dummy = ListNode(-1)
        dummy.next = head
        cur = dummy
        while cur and cur.next:
            if cur.next.val not in dic:
                dic.add(cur.next.val)
                cur = cur.next
            else:
                cur.next = cur.next.next
        return dummy.next
        

            
```