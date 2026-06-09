### 解题思路
引入快慢指针，若两指针指向同一节点则说明有环;否则无环。
另外考虑过引入一个集合，每访问一个节点就把该节点放入集合中;之后每次访问新的节点，就查询在集合中是否出现过，若有则说明有环。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        fast = slow = head
        while fast and slow and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast :
                return True
        return False
```