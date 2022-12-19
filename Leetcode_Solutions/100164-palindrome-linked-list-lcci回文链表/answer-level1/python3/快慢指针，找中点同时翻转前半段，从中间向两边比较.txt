```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        slow, fast, last = head, head.next, None
        while fast.next and fast.next.next:
            tmp = slow.next
            slow.next = last if last else None
            last = slow
            slow = tmp
            fast = fast.next.next
        middle = slow.next.next if fast.next else slow.next # 区分链表长度为奇数偶数的情况,middle为后半段的开始
        slow.next = last #完成前半段翻转
        while middle:
            if slow.val != middle.val:
                return False
            slow, middle = slow.next, middle.next
        return True
```
