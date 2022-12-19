类似于“链表中环的入口结点”一题

双指针，一快一慢，一个指针p每次走一步，一个指针q每次走两步
如果链表中有环，那么它们必定会相遇
如果中途其中一个指针为None，说明链表没有环


```
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        
        # 因为while条件是p!=q，如果pq同时从head出发就永远到不了while内部
        p = head.next
        q = head.next.next
        
        '''此处q如果为None仍会进循环，在判断if q.next的时候就会报错，所以要在上一次if判断的时候避免出现q.next.next=None的情况'''
        while p != q:
            '''多层级结构一定要依次判断直到上一层级'''
            if p and q and q.next:
                p = p.next
                q = q.next.next
            else:
                return False
        
        return True
```
