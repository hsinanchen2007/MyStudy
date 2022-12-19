### 解题思路
第一种用数组存节点，最后返回第-k个节点即可；第二种使用快慢指针，先让快指针多走k布，然后两个指针一起走，快指针到末尾时，慢指针就是答案。

### 代码

```python3

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        s = []
        t = head
        while t is not None:
            s.append(t)
            t = t.next
        return s[-k]

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        fast = head
        slow = head
        for i in range(k):
            fast = fast.next
        while fast is not None:
            fast = fast.next
            slow = slow.next
        return slow
```