方法一:利用双指针进行遍历
```
class Solution(object):
    def deleteNode(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if not head:
            return None
        result = head
        first = head
        second = head.next
        if first.val == val:
            return second
        while second:
            if second.val == val:
                first.next = second.next
                second = first.next
            else:
                first = first.next
                second = second.next
        return result
```

方法二: 利用单指针来进行遍历
```
class Solution(object):
    def deleteNode(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if not head:
            return None
        result = head
        first = head
        if first.val == val:
            return first.next
        else:
            while(first.next.val != val):
                first = first.next
            first.next = first.next.next
        return result
```
