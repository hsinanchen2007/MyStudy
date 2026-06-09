### 解题思路
全部拆掉存到字典中，然后按照规则重组。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        hash_table = {}
        ph = head
        post = 0
        while ph:
            tmp = ph.next
            ph.next = None
            hash_table[post] = ph
            post += 1
            ph = tmp
        ph = head  
        for i in range(1, post):
            if i % 2 == 1:
                ph.next = hash_table[post - 1 - i//2]
            else:
                ph.next = hash_table[i//2]
            ph = ph.next
```