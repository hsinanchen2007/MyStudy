参考[@tianwj](/u/tianwj)的算法中同位相加的算法，运行时发现出现错误，后更改为下列代码发现可以正常提交：
```
代码块
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        add = 0
        l3 =l4 = ListNode(0)
        while l1 or l2 or add:
            if l1 or l2:
                if l1:
                    num = l1.val +add
                    if l2:
                        num = num + l2.val
                elif l2:
                    num = l2.val + add
                    if l1:
                        num = num + l1.val
            else:
                num = add
            add = 0
            if num//10 >0:
                add = 1
                num = num%10
            l3.val = num
            
            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2
            if l1 or l2 or add:
                l3.next = ListNode(0)
                l3 = l3.next
        return l4
```
