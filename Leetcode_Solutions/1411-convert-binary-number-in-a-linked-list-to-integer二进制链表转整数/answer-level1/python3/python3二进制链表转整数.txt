### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        ptr=head
        num=0
        while ptr:
            num*=2
            num+=ptr.val
            ptr=ptr.next
        return num
```

![image.png](https://pic.leetcode-cn.com/49349e43ba98541d793d9c8c119272aabfc8946487e8f5b23e52f64c0bd23aaa-image.png)
