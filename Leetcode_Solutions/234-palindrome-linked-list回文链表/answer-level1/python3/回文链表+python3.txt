### 直接法

先把链表转成数组，再判断是否为回文链表，空间复杂度O(n)不符合要求。

```
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None or head.next == None:
            return True
        target = []
        while head:
            target.append(head.val)
            head=head.next
        p = (len(target)-1)//2+1
        q = (len(target))//2
        
        return target[0:p]==target[q:len(target)][::-1]
```