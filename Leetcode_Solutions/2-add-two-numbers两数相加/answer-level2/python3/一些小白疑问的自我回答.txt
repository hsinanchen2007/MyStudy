### 小白的解题思路
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#    def __init__(self, x):
#        self.val = x
#        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        """
        1.如何理解逆序？用笔算，也是从个位数开始
        2.如何理解dummyNode？这是个哑结点，用来返回列表（链表）l3
        3.如何理解carry？9+9=18，而每个结点只能存储一个数，所以下一个结点要+carry(=1)
        4.为什么不是x=l1.val if l1.val else 0?如果输入是[1,8],[0]就会出错，l2的第二个结点根本不存在，无法判断
        """
        dummyNode=ListNode(0) #值不重要
        l3=dummyNode
        carry=0  #进阶初始化，carry=0或1
        while(l1 or l2):
            x=l1.val if l1 else 0  #如果l1的值为真，返回给x；否则x=0（{},[],null,False,()这些数据都为假）
            y=l2.val if l2 else 0  ？
            sum_l1l2=x+y+carry
            carry=sum_l1l2//10
            l3.next=ListNode(sum_l1l2%10)  #这两行代码可以使用divmod()
            l3=l3.next
            if(l1 != None):l1=l1.next  #不能判断l1.next!=None，否则l1.next永远不等于0，进入死循环
            if(l2 != None):l2=l2.next
        if(carry==1):
            l3.next=ListNode(1)
        return dummyNode.next  