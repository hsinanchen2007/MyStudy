```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        # 所谓移动 就是将链表的最后一个节点换到第一个
        # 移动k次
        # 有一个优化：链表节点个数对k取余数才是真正要移动的次数
        
        # 特殊情况
        if not head:
            return head
        # q=ListNode(0)
        # 初始化
        p,t,q=head,head,head
        # 找到节点个数
        count=0
        while t!=None:
            count+=1
            t=t.next
        # 计算真正要移动的次数tmp
        # 1%5=1
        # 2%5=2
        # ...
        # 5%5=0
        tmp=k%count
        # 如果tmp等于0的话 就是原链表 无须移动
        if tmp==0:
            return q
        # 不是0的情况
        # 1 (4) 2 (3) 3 (2) 4 (1) 5
        # 找到需要断开的位置
        len1=count-tmp-1
        while len1>0:
            q=q.next
            len1-=1
        # 链接节点
        # 记住新链表的头节点
        r=q.next
        #链尾置为None
        q.next=None
        m=r
        # 找到长一段的最后一个节点
        while tmp-1>0:
            m=m.next
            tmp-=1
        # 尾节点链接原头节点
        m.next=p
        # 返回新的头节点
        return r
```
