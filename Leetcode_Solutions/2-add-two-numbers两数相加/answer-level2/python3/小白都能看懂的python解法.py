代码写的比较繁琐，力争让各位起步的朋友全部看懂解法。
主要思路：
1.分别遍历两个链表，将链表中的数据全部存入列表当中。

2.如果两个链表长度不等，对长度较短的列表进行补0操作。

3.将两个列表数值相加，如果求和数值小于10，则用和覆盖当前值；如果求和数值大于10，则用求和数值-10覆盖当前值，并在列表的下一位进1。

4.将求和后的列表数值赋值给新链表，返回新链表。

```
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        curr1 = l1
        curr2 = l2
        stack1 = []
        stack2 = []
        c1 = 0
        c2 = 0
        ncurr = ncu = ListNode(0)
        while curr1 is not None:
            stack1.append(curr1.val)
            curr1 = curr1.next
            c1 = c1 + 1
        while curr2 is not None:
            stack2.append(curr2.val)
            curr2 = curr2.next
            c2 = c2 + 1    
        while c1 > c2:
            stack2.append(0)
            c2 = c2 + 1
        while c1 < c2:
            stack1.append(0)
            c1 = c1 + 1  
        for i in range(c1):
            if stack1[i] + stack2[i] < 10:
                stack1[i] = stack1[i] + stack2[i]
            else:
                stack1[i] = stack1[i] + stack2[i] -10
                if i+1 < c1:
                    stack1[i+1] = stack1[i+1] + 1
                else:
                    stack1.append(1)
        for i in range(len(stack1)):
            ncurr.next = ListNode(stack1[i])
            ncurr = ncurr.next
        return ncu.next
```
