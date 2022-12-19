### 解题思路
72 ms, faster than 52.77% of Python3 
快慢指针取到中点, 不管奇偶, 总是取慢指针, 
然后翻转后半部分链表, 此时不需要切断前半部分和后半部分的链接, 因为后半部分长度总是大于等于前半部分

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        slow = fast = head
        while fast and fast.next: # 快慢
            fast = fast.next.next
            slow = slow.next
        pre = None
        while slow: # 反转后半部分链表
            tmp = slow.next
            slow.next = pre
            slow, pre = tmp, slow
        while pre:  #and head: # 直接遍历, 后半部分长度总大于等于前半部分 
            if pre.val!=head.val:
                return False
            pre, head = pre.next, head.next
        return True
```