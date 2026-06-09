```
双指针结构：
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        last=None
        anext=head
        while head:
            anext=head.next
            head.next=last
            last=head
            head=anext
        return last


递归思路：
直接从最后一个点开始改，返回上一层
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        def reverse(last,node):
            if not node.next:
                node.next=last
                return node
            res=reverse(node,node.next)
            node.next=last    
            return res 
        return reverse(None,head)
