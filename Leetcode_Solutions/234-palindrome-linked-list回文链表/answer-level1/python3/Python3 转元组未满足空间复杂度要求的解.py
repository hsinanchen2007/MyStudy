```python []
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        target = []
        while head:
            target.append(head.val)
            head=head.next    
        return target == target[::-1]
```
