# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # 思路：算出最后一个结点值，然后该节点之后的结点反转链表，然后该节点之前
        # 的结点每隔一个插入一次即可
        if head==None or head.next==None:return head
        count=0
        p=head
        while p!=None:
            count+=1
            p=p.next
        mid=int((count+1)/2)+1
        p=head
        for i in range(mid-2):
            p=p.next
        # 将链表从中间断开
        premidli=p
        p=p.next
        premidli.next=None
        # 找到了中间点，反转后面的
        midli=p
        q=None
        while p.next!=None:
            m=p.next
            p.next=q
            q=p
            p=m
        p.next=q
        n=head
        # 在将前面的部分隔一个插入一下后面的链表
        # print(head)
        for i in range(int(count/2)):
            nnext=n.next
            pnext=p.next
            n.next=p
            p.next=nnext
            p=pnext
            n=nnext
        return head
            
            
            
            
            
            
            
            
            