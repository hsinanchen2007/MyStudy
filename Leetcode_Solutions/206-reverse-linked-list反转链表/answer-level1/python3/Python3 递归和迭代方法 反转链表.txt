
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None



# 方法一:递归
# 1.得到尾部节点:p = self.reverseList(head.next)
# 2.翻转当前节点：head.next.next = head
# 3.拆掉当前节点的next：head.next = None
class Solution:
     def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head 
        p = self.reverseList(head.next)
        head.next.next = head 
        head.next = None 
        return p 

# 方法二：迭代
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        preNode=None
        while head:
            # 原本的next节点的值存储下来
            postNode=head.next
            # 将节点的指向前方
            head.next=preNode
            # 继续将节点往后推，当前节点head变为preNode,当前节点的后节点(postNode)为变为head节点
            preNode=head
            # 不能使用head.next因为上方已经修改了。只能使用postNode
            head=postNode
```
