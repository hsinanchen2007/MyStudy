### 解题思路
此处撰写解题思路
模拟正常相加，
首先设立一个返回node result(0)
当前node curr=result
p,q 指向l1,l2
初始 进位 inc=0
p q有1个非空 进行循环
循环 (p not none or q not none)：
    if p存在,x 取p.val else x取0 
    if q存在,y 取q.val else y取0
    和sum=x+y+inc
    得到的当前位余数 re 新建linkNode(re)
    将curr-next 设为 reNode 
    curr指向curr-next 即余数节点 
    即 将余数节点加入result链，
    if p p=p-next 
    if q q=q-next
当p q均为none 退出循环
此时检查进位 将进位插入到result链末尾
    curr-next=LinkNode(inc)
    得到 result链条
    因为result 链条头节点为0，
    返回 result-next
    


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode(0)
        curr=result
        inc = 0
        p,q=l1,l2
        while (p or q):
            if(p):
                x=p.val
            else:
                x = 0
            if (q):
                y = q.val
            else:
                y = 0
            sum = x + y + inc
            inc, re = divmod(sum, 10)
            curr.next = ListNode(re)
            curr = curr.next
            if (p):
                p = p.next
            if (q):
                q = q.next

        if inc > 0:
            curr.next = ListNode(inc)

        return result.next
        
```