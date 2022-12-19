### 解题思路
正序保存在数组里，最后将数组倒序输出。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        num = []
        node = head
        while node:
            num.append(node.val)
            node = node.next
        return num[::-1]
```