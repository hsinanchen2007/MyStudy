### 解题思路
此处撰写解题思路
快慢双指针, 移动的过程中需要反向. 重点是慢指针停止的地方, 如果最后是fast为空, 说明链表长度是奇数, 右端开始比较的位置需要向后移动一位
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        prepre = pre = slow = fast = head
        while fast and fast.next:
            prepre = pre
            pre = slow
            slow = slow.next
            if prepre != pre: pre.next = prepre
            fast = fast.next.next
        if fast: # indicate list is odd, then right we start in slow.next
            slow = slow.next
        while slow and pre:
            if slow.val != pre.val:
                return False
            slow = slow.next
            pre = pre.next
        return True
```