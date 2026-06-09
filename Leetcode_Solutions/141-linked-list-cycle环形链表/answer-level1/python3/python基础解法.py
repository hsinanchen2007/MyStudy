### 解题思路
1. 通过快慢指针是否相等来判断是否有环的存在
2. 通过set集合判断是否存在环

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # if head == None or head.next == None:
        #     return False
        # low = head
        # fast = head.next
        # while low != fast:
        #     if fast == None or fast.next == None:
        #         return False
        #     else:
        #         low = low.next
        #         fast = fast.next.next
        # return True

        if head is None or head.next is None:
            return False
        seen = set()
        while head:
            if head in seen:
                return True
            else:
                seen.add(head)
            head = head.next
        return False


```