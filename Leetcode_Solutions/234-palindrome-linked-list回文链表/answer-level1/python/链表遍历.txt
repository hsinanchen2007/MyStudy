遍历链表，顺序压栈，反转栈比较
```
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        cur = head
        pos_list = []
        # 遍历链表，压栈
        while cur is not None:
            pos_list.append(cur.val)
            cur = cur.next
        # reverse栈后比较
        inv_list = pos_list[::-1]
        
        return True if inv_list==pos_list else False
```
