### 解题思路
此处撰写解题思路
难点在于将数字变为逆向的链表 和 从逆向链表转为数字 
写几个方法 就搞定。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        res=self.parseNode(l1)+self.parseNode(l2)
        return self.produceNode(res)

    def parseNode(self,l1: ListNode):
        l=l1
        num_list=[]
        while l !=None:
            num_list.append(str(l.val))
            l=l.next
        num_list=num_list[::-1]
        num_str=""
        for num in num_list:
            num_str+=num
        return int(num_str)
    
    def produceNode(self, num) ->ListNode:
        str_num=str(num)
        str_num=str_num[::-1]
        len_num=len(str_num)
        l=None
        node_list=[ListNode(a) for a in str_num]
        l=node_list[0]
        l0=l
        for i in range(len_num-1):
            l0.next=node_list[i+1]
            l0=node_list[i+1]
        return l



```