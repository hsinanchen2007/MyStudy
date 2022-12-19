### 解题思路
思路很简单：
1， 给ListNode添加prev属性，编程双向链表
2， 然后从头到位和从尾部到头部进行比较就行，

事件复杂度O(n)
空间复杂度O(1)
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        '回文表示翻转相同, 添加prev属性'
        p1 = None
        p2 = head
        while p2:
            p2.prev = p1
            p1, p2 = p2, p2.next

        p2 = p1
        p1 = head
        while p2:
            if p1.val != p2.val:
                return False
            p1 = p1.next
            p2 = p2.prev
        
        return True
        
```