最开始有点拿到题不知道怎么入手，看了一下别人的hint发现可以用反转半截链表进行对比，双指针获得后半截链表的head
要注意链表的奇偶长度，考虑后半截链表的头结点从哪里开始

```python
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        if not head.next.next:
            return head.val == head.next.val
        
        p = head.next
        q = head.next.next
        # p = head
        # q = head

        '''如果是这样判断，那么考虑奇偶情况，反转要从p开始
        避免出现[1,2,3,4,2,1]的情况'''
        while q and q.next:
            p = p.next
            q = q.next.next
        
        second = self.reverseList(p)

        '''如果是这样判断，那么考虑奇偶情况，反转要从p.next开始'''
#         while q.next and q.next.next:
#             p = p.next
#             q = q.next.next
        
#         second = self.reverseList(p.next)
        return self.check(head, second)
    
    def check(self, p, q):
        while p and q:
            if p.val != q.val:
                return False
            p = p.next
            q = q.next
        return True
        
    def reverseList(self, head):
        pre = None
        cur = head
        
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
            
        return pre     
```
