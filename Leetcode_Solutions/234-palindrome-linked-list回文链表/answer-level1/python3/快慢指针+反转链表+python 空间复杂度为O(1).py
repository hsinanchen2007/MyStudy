核心思想：利用快慢指针,找到链表的中心位置，然后一个指针跟在慢指针后，慢指针向前，反转链表。再比较前后两个链表是否一样
```
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 反转链表，快慢指针,找到链表的中心位置，一个指针跟在慢指针后反转链表
        RHead = None
        if not head or not head.next:
            return True
        else:
            slow = head
            quick = head.next

        while quick and quick.next:
            temp = slow
            slow = slow.next
            quick = quick.next.next
            temp.next = RHead
            RHead = temp
        
        if quick:  # 偶数
            quick = slow.next
            slow.next = RHead
        else:
            quick = slow.next
            slow = RHead

        while quick and slow:
            if quick.val != slow.val:
                return False
            else:
                quick = quick.next
                slow = slow.next
        return True

```
