# 三个步骤
    - 先找到中间节点；
    - 再将后半边反转，如果回文则前半边应该和后半边完全相同，一旦不同就返回错误；
    - 判断结束之后把链表再翻转回来

```
class Solution:
    #用于判断是否是回文
    def isPalindrome(self, head: ListNode) -> bool:
        if not head: return True 
        before=self.find_half(head)
        after_head=self.reverse_list(before.next)
        flag=True
        before=head
        after=after_head
        while flag and after:
            if before.val!=after.val:
                flag= False
            before=before.next
            after=after.next
        #处理结束之后把链表变回来
        before.next=self.reverse_list(after_head)
        return flag
    #用于快慢指针找到中间节点slow
    def find_half(self,head):
        slow,fast=head,head
        while fast.next and fast.next.next:
            slow=slow.next
            fast=fast.next.next
        return slow
    #用于翻转后半边的节点
    def reverse_list(self,head):
        pre=None
        cur=head
        while cur:
            tmp=cur.next
            cur.next=pre
            pre=cur
            cur=tmp
        return pre
```
