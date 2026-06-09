class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        str1 = ''
        str2 = ''
        while l1 != None:
            str1+=str(l1.val)
            l1 = l1.next
        while l2 != None:
            str2+=str(l2.val)
            l2 = l2.next
        n1 = int(str1[::-1])
        n2 = int(str2[::-1])
        sm = n1 + n2
        str3 = str(sm)
        str3 = str3[::-1]
        l3 = ListNode(int(str3[0]))
        l4 = l3
        for i in str3[1:]:
            temp=ListNode(int(i))
            l3.next = temp
            l3 = temp
        return l4