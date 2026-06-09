### 解题思路
两个栈分别存储两个链表内容
相加时两个栈同时出栈一个元素进行相加，保留进位
每次相加前判断每个栈和进位是否为空，用头插法给新链表添加节点
返回新链表
### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode    
        """
        #建栈
        s1,s2 = [],[]
        while l1: 
            s1.append(l1.val)
            l1 = l1.next
        while l2: 
            s2.append(l2.val)
            l2 = l2.next
        newHead = ListNode(-1) 
        carry = 0  #进位
        #开始相加
        while s1 or s2 or carry:
            n1,n2 = 0,0
            n1 = s1.pop() if s1 else 0
            n2 = s2.pop() if s2 else 0
            count = carry + n1 + n2
            s = count % 10   #得到个位数
            #头插法
            newNode = ListNode(s)
            newNode.next = newHead.next
            newHead.next = newNode
            #进位处理
            carry = int(count/10)
        return newHead.next

        
```