### 解题思路
求倒数第几个的时候，如果不能使用len()进行计算，然后再遍历，就要想到快慢指针，让fast指针先走k步，然后再让两个指针一起走，知道fast指向None

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        fast,slow = head,head
        for _ in range(k):
            fast = fast.next
        while fast:
            fast = fast.next
            slow = slow.next
        return slow
        
```