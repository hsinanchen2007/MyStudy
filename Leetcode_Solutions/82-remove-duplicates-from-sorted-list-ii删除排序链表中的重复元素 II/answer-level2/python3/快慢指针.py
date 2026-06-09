```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if (not head) or (not head.next):
            return head
        slow = None
        curr = head
        fast = head.next
        while fast:
            if not curr.val == fast.val: # 值不相等时
                if curr.next == fast:
                    slow = curr
                else:
                    if slow:
                        slow.next = fast
                    else:
                        head = fast
                curr = fast
            else:
                if not fast.next:
                    if slow:
                        slow.next = None
                    else:
                        return None
            fast = fast.next                    
        curr.next = None 
        return head
```
