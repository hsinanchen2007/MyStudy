### 解题思路
此处撰写解题思路
这个写法其实没什么时间效率和空间效率
但就是看着简单舒服  哈哈哈哈哈哈哈
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        p, gs = head, None
        while p:
            gs , gs.next , p = p , gs ,p.next
        return gs
```