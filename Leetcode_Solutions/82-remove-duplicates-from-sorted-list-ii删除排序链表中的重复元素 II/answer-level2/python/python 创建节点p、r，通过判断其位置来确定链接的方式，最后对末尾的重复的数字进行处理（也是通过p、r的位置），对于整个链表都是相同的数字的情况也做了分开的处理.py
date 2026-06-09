```
if head==None or head.next==None:
            return head
        q=ListNode(-1)
        q.next=head
        p=q
        r=head
        flag=0
        while r.next:
            # 一旦有不重复的即可完成删除 但末尾的重复的数字却无法删除
            if r.val!=r.next.val:
                flag=1
                if p.next==r:
                    p=r
                else:
                    p.next=r.next
            r=r.next
        # 整个链表都是同一个数字在重复
        if flag==0:
            return None
        # 链表最后数字重复
        # 解决1，2，2，2，3，3，3此类情况 1，3，3，3
        # 此时p->1 r->3 p.next!=r 则直接p.next=None#
        # 类似1，2，2，2，4 while循环结束后 1，4 p.next==r 无须去掉重复的数字
        if p.next!=r:
            p.next=None
        # 返回头节点
        return q.next
```
