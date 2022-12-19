### 解题思路
中间节点遇奇数后移，偶数不动，类似快慢指针法
时间复杂度：O(N)
空间复杂度：O(1)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        middle = head
        cur = head
        i = 0
        while cur is not None:
            if i & 1:
                middle = middle.next
            cur = cur.next
            i += 1
        return middle
```