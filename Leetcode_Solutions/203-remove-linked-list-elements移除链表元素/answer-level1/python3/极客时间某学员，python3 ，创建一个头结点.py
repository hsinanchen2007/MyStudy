我是最菜的极客时间学员之一。
创建一个新的头结点，指向当前头结点。

pp指向该结点，如果要处理的链表的第一个元素要被删除，那么，now.next 就被修改了；
也就是pp.next 被修改了。
对于需要处理的链表，需要砍头的话，也不怕。 把特殊情况普通化。


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if not head :return 

        now=ListNode(val+1) #build the start point
        now.next =head
        pp=now
        
        while now and now.next :  # both 
            
            if now.next.val == val:
                now.next=now.next.next  #delete it 
                #now=now.next  #now is not move 
                
            else:
                now =now.next   #move
                
        return pp.next