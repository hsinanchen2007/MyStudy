### 解题思路
分析：链表操作、相加进位

按节点相加
注意保留起始节点指针
循环递归都能完成

骚操作：全部转换为字符串，进位默认隐藏在转换过程中，但我觉得意义不大，复杂度没有降低，常规算法封装一下就是操作符重载


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        newNode=ListNode(0)
        ansNode=newNode
        flag=-1
        while l1 or l2 or flag:
            if flag!=-1:
                newNode.next=ListNode(0)
                newNode=newNode.next
            else:
                flag=0
            if l1 and l2:
                sum=l1.val+l2.val
                l1=l1.next
                l2=l2.next
            elif l1:
                sum=l1.val
                l1=l1.next
            elif l2:
                sum=l2.val
                l2=l2.next
            else:
                sum=0
            newNode.val=(sum+1)%10 if flag==1 else sum%10
            flag=1 if sum+flag>9 else 0 
        return ansNode
```
```python3
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        newNode=ListNode(0)
        ansNode=newNode
        flag=0
        while l1.val>=0 or l2.val>=0:
            x=l1.val if l1.val>=0 else 0
            y=l2.val if l2.val>=0 else 0
            sum=x+y+flag
            flag=sum//10
            newNode.val=sum%10
            l1=l1.next if l1.next else ListNode(-1)
            l2=l2.next if l2.next else ListNode(-1)
            if l1.val>=0 or l2.val>=0 or flag:
                newNode.next=ListNode(0)
                newNode=newNode.next
        if flag==1:
            newNode.val=1
        return ansNode
```