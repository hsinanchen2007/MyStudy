### 解题思路
先转换为数组再判断

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        num = []
        node = head
        while(node):
            num.append(node.val)
            node = node.next
        length = len(num)
        for i in range(length//2):
            if num[i] != num[length - 1 - i]:
                return False
        return True
```