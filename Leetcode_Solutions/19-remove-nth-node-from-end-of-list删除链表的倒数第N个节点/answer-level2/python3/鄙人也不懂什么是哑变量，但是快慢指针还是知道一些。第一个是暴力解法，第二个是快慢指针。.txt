    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        val=[]
        p=head
        while p!=None:
            val+=[p.val]
            p=p.next
        val.pop(-n)
        if not val:
            return None
        else:
            newllist=ListNode(val[0])
            q=newllist
            for i in val[1:]:
                q.next=ListNode(i)
                q=q.next
            return newllist


    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        newllist=None
        val=[]
        p=head
        k=0
        while p!=None:
            val+=[p.val]
            p=p.next
            if len(val)==n+1 and k==0:
                newllist=ListNode(val[0])
                q=newllist
                k+=1
                val.pop(0)
            elif len(val)==n+1 and k==1:
                q.next=ListNode(val[0])
                q=q.next
                val.pop(0)
        if not newllist and not bool(val[1:]):
            return None
        if not newllist and bool(val[1:]):
            newllist=ListNode(val[1])
            q=newllist
            for i in val[2:]:
                q.next=ListNode(i)
                q=q.next
            return newllist
        else:
            for i in val[1:]:
                q.next=ListNode(i)
                q=q.next
            return newllist