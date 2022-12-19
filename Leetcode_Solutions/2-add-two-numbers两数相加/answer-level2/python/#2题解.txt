### 解题思路2
直接链表基础上相加得到最终链表

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        lst = ListNode(0)
        lst_copy = lst
        flag = 0
        while l1 or l2:
            if l1:
                num1=l1.val
                l1=l1.next
            else:
                num1=0
            if l2:
                num2=l2.val
                l2=l2.next
            else:
                num2=0
            num = num1+num2+flag

            flag=num//10
            num=num%10
            lst.next = ListNode(num)
            lst = lst.next
                
        if flag==1:
            lst.next = ListNode(1)
        return lst_copy.next
```
### 解题思路1
先将链表转换成列表，再转换成数字相加后，再转换成列表，用以生成最后的链表

### 代码
```
#Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        lst1=[]
        lst2=[]
        while l1 != None:
            lst1.append(l1.val)
            l1=l1.next
        while l2 != None:
            lst2.append(l2.val)
            l2=l2.next
        lst1.reverse()
        lst2.reverse()
        num1=0
        num2=0
        for i in lst1:
            num1 = num1 * 10 + i
        for j in lst2:
            num2 = num2 * 10 + j
        num = num1+num2
        lst = list(map(int,str(num)))
        lst.reverse()
        l=ListNode(lst[0])
        l_copy = l
        if len(lst)>1:
            for k in lst[1:]:
                l.next=ListNode(k)
                l = l.next
        return l_copy
```
