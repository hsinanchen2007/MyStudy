### 解题思路
1. 快慢指针，快慢指针相遇后，慢指针与新的慢指针相遇的点就是入口处
2. 哈希表

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        # if not head or not head.next : 
        #     return 
        # # 快慢指针
        # slow = head
        # fast = head
        # # 重新开始
        # start = head
        # while fast and fast.next:
        #     slow = slow.next
        #     fast = fast.next.next
        #     # 找到相遇点
        #     if slow == fast:
        #         while slow != start:
        #             slow = slow.next
        #             start = start.next
        #         return slow
        # return None

        lookup = set()
        node = head
        while node:
            if node in lookup:
                return node
            lookup.add(node)
            node = node.next
        return None
```