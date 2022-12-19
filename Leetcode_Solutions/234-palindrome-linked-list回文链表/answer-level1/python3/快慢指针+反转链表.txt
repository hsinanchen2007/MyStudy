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
    def isPalindrome(self, head: ListNode) -> bool:
        fast = slow = head
        # 快慢指针定位中点
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        # 后半部分反转链表，返回链表头
        fast = slow
        p = None
        while fast:
            tmp = fast.next
            fast.next = p
            p = fast
            fast = tmp
        fast = p
        # 开始比较
        slow = head
        while fast:
            if slow.val == fast.val:
                slow, fast = slow.next, fast.next
            else:return False
        return True

        
        



        
```