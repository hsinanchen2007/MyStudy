```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        def reverse(head):
            pre = None
            while head:
                pre, head.next, head = head, pre, head.next
            return pre
        if not head or not head.next:
            return True
        fast = slow = head
        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            
        if fast.next == None: #is odd slow is mid
            isodd = True
        else: # event slow is left mid
            isodd = False
        
        #cut link
        fast = slow.next
        slow.next = None
        slow = reverse(head)
        if isodd:
            slow = slow.next #skip mid
        
        while fast and slow:
            if fast.val != slow.val:
                return False
            fast, slow = fast.next, slow.next

        return True

```
代码优化，翻转后半段，避免判断奇偶
```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        def reverse(head):
            pre = None
            while head:
                pre, head.next, head = head, pre, head.next
            return pre
        if not head or not head.next:
            return True
        fast = slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        #slow is mid or right mid, so reverse right half, do not need cut left and right
        # for odd 1->2->3->(4)->5->6->7->N
        # 1->2->3->4->N   7->6->5->4->N
        # for event 1->2->3->4->(5)->6->7->8->N
        # 1->2->3->4->5->N  8->7->6->5->N
        slow = reverse(slow)
        
        while head and slow:
            if head.val != slow.val:
                return False
            head, slow = head.next, slow.next

        return True

```
