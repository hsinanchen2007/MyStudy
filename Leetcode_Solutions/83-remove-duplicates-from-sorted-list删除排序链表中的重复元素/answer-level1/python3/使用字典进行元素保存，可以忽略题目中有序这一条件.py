如题。
```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        whole = head
        nums = {}
        if head == None:
            return 
        while head:
            if head.val not in nums:
                nums[head.val] = head.val
                prev = head
                head = head.next
            else:
                prev.next = head.next
                head = head.next
        return(whole)
```
