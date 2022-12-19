### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# ListNode的样子大概是这样 ListNode{val: 9, next: ListNode{val: 9, next: None}}
# 大概样子就跟字典一样

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry_flag = 0
        two_sum = 0
        # back l1和l2相加的值存到这个ListNode类中，这个变量中始终都有一链
        back = ListNode(0) 
        p = back
        while True:

            # 在while中主要两块这一块是l1.val和l2.val相加
            if l1 != None and l2 != None:
                two_sum = l1.val + l2.val + carry_flag
                if two_sum > 9:
                    back.val = l1.val + l2.val - 10 + carry_flag
                    carry_flag = 1
                else:
                    back.val = l1.val + l2.val + carry_flag
                    carry_flag = 0      

            '''这一段主要是进行判断'''
            # 判断返回时的条件，只有当l1和l2的next都是None是才返回
            if l1.next ==None and l2.next == None:
                break
            elif l1.next != None and l2.next != None:
                l1, l2 = l1.next, l2.next
            elif l1.next == None and l2.next != None:
                l1, l2 = ListNode(0), l2.next
            elif l1.next != None and l2.next == None:
                l1, l2 = l1.next, ListNode(0)
            back.next = ListNode(0)
            back = back.next


        if carry_flag == 1:
            back.next = ListNode(1)
        return p

```