### 解题思路

用了字典的有序性和哈希性。

### 代码

```python []
class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        d = {}
        while head:
            if head.val not in d:
                d[head.val] = head
            head = head.next
        ans = tmp = ListNode(0)
        for head in d.values():
            tmp.next = head
            tmp = tmp.next
        tmp.next = None
        return ans.next
```