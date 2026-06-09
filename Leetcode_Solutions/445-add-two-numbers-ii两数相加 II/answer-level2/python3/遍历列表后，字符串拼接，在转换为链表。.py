class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l1list,l2list='',''
        #遍历l1
        while l1:
            l1list+=str(l1.val)
            l1=l1.next
        #遍历l2
        while l2:
            l2list+=str(l2.val)
            l2=l2.next
        l3list=str(int(l1list)+int(l2list))
        #设置哑变量
        dummy=ListNode(0)
        p=dummy
        for i in l3list:
            p.next=ListNode(i)
            p=p.next
        return dummy.next
```
