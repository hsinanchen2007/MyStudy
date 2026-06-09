class Solution:
        def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:

        
        stra = ''
        strb = ''
        while l1 is not None:
            stra = str(l1.val) + stra
            l1 = l1.next
        while l2 is not None:
            strb = str(l2.val) + strb
            l2 = l2.next
        res = str(int(stra) + int(strb))
        res = res[::-1]
        length = len(res)
        rootnode = ListNode(int(res[0]))
        if length == 1:
            return rootnode
        for i in range(length):
            if i == 0:
                #rootnode = ListNode(int(res[0]))
                tempnode = rootnode
            else:
                tempnode.next = ListNode(int(res[i]))
                tempnode = tempnode.next

        return rootnode