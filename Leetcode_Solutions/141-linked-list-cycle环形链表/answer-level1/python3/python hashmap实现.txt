### 解题思路
python中可使用set类型实现hashmap

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        hashmap=set()
        while head:
            if head not in hashmap:
                hashmap.add(head)
            else:
                return True
            head=head.next
        return False
        

```