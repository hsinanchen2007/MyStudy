**首先用before和after两个指针分别存储小于、大于x的节点，两节点不断更新(与head同时更新)直至到达尾部，而再用两个哨兵节点before_head和after_head存储最开始的头节点，通过这二者进行连接。**
```
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        before =before_head = ListNode(0)
        after = after_head = ListNode(0)
        while head:
            if head.val < x:
                before.next=head  #before_head的下一个指向head
                before=before.next
            else:
                after.next=head
                after=after.next

            head=head.next
        after.next=None  #将after尾部指向空
        before.next=after_head.next  #将before的下一个指向after_head的下一个

        return before_head.next
```
