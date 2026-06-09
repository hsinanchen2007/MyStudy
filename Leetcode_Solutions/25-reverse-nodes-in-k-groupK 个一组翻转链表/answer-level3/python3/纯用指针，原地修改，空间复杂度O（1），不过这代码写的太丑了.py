纯用指针，在翻转全部链表操作的基础上改进。花了一整个下午时间，快自闭了
```
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

head=ListNode(1)
h=head
for i in range(9):
    head.next=ListNode(i+2)
    head=head.next
head=h
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head==None:
            return head
        l=head
        q=head
        p=q.next
        flag=0
        while 1:
            count=0
            for i in range(k):
                if l!=None:
                    l=l.next
                    count+=1
            if count==k:
                r=l
                j=0
                while j!=k:
                    q.next=r
                    r=q
                    q=p
                    if p:
                        p=p.next
                    j+=1
                flag+=1
                if flag==1:
                    head=r
                res=r
                for i in range(k-1):
                    res=res.next
                res2=res
                m=0
                for i in range(k):
                    if res2.next:
                        res2=res2.next
                        m+=1
                if m==k:
                    res.next=res2
            else:
                break
        return head
```