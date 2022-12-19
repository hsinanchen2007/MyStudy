```
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        p = q = head
        count = 1
        p_pre = head_pre = ListNode(0) #第二次提交失败在于没有设置head_pre
        p_pre.next = head
        while count < m: #先定位到要反转的首尾p和q,p->2,q->4
            p_pre = p
            p = p.next
            count += 1
        count = 1
        while count < n:
            q = q.next
            count += 1
        
        p_pre.next = q #使1—>4
        p_pre = q.next #为2->5做准备
        count = 0
        while count < n-m+1:
            #print(p.val)
            p_next = p.next
            p.next = p_pre
            p_pre = p
            p = p_next
            count += 1
        return head_pre.next
```
