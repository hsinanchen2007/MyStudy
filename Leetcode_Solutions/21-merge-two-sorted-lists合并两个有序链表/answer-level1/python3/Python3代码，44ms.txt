可以先把l1和l2两个链表里的值都拿出来放到一个数组中，然后在sort()排序一下，之后在根据数组中的值构建一个新链表即可
        s = []
        if(l1 == None and l2 != None):
            return l2
        elif(l1 != None and l2 == None):
            return l1
        elif(l1 != None and l2 != None):
            while(l1):
                x = l1.val if l1 else 0
                s.append(x)
                if(l1 != None):
                    l1 = l1.next
            while(l2):
                y = l2.val if l2 else 0
                s.append(y)
                if(l2 != None):
                    l2 = l2.next
            s.sort()
            re = ListNode(0)
            r = re
            for i in range(len(s)):
                r.next = ListNode(s[i])
                r = r.next
            re = re.next
            return re