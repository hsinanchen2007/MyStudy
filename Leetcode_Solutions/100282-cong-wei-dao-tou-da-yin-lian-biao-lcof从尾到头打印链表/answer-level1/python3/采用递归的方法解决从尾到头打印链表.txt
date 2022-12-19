### 解题思路
采用递归的方法，从前往后递归，从后往前打印的效果。构思很巧妙。但是很耗时间
举个例子：
f(n)= f(n-1) + n
f(3)= f(2) +3 = f(1) + 2 +3 = f(0) + 1 + 2 +3 = 0 + 1 + 2 +3

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if head:
            return self.reversePrint(head.next)+[head.val]
        else:
            return []
      
```