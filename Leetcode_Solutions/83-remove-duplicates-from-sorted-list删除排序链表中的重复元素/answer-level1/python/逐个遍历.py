### 解题思路
时间复杂度：O（n）
空间复杂度：O（n）

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return None
        nums = [head.val]
        pri = head
        nex = head.next
        while nex:
            if nex.val not in nums:
                nums.append(nex.val)
                nex = nex.next
                pri = pri.next
            else:
                pri.next = nex.next
                del nex
                nex = pri.next
                
        return head
```