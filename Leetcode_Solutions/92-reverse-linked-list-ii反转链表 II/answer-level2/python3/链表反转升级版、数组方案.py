多个链表操作（具体步骤看源码吧，相信你们也是很厉害的）、数组简单易懂
 



        '''
        if not head :return head
        root = head         #循环链表
        knit = ListNode(None)#结果链表
        knit.next = head
        pre = knit          #记录链表
        i = 1   #用于记录位置
        while i < m and root:
            pre = root
            root = root.next
            i +=1
        #记录m位置前一个节点、m节点
        before = pre
        after = root

        #链表反转
        while i<=n and root:
            nex = root.next
            root.next = pre
            pre = root
            root = nex
            i +=1

        #判断特殊情况 m==1 只需要将反转后的链表尾节点指向还没有反转的后续链表
        #if m==1:
          #  after.next = root
           # return pre
        #头尾相接
        before.next = pre
        after.next = root
        return knit.next
        '''



        if not head :return head
        result = []
        while head:
            result.append(head.val)
            head= head.next
        result[m-1:n] = reversed(result[m-1:n])
        final = ListNode(None)
        root = final
        for i in result:
            root.next = ListNode(i)
            root = root.next
        return final.next



