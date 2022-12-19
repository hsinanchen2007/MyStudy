### 解题思路
小白刚开始做，不是很熟练，参考了官方给出的思路和java版的代码。

对于实际解决一个问题，总是要考虑很多特殊情况，例如，两者都为空的时候，直接输出空结点。例如两者长度不同，那么另一个就应该用0参加计算。以及计算到最后还要进位，那么还需要添加一个结点。
每次写循环的时候，都要考虑好内部变量的修改，将第一次的工作和后面的工作要进行统一。

这一节主要学习python实现单链表这种数据结构，以及单链表的遍历，注意python两种表达：
num1 = l1.val if 条件 else 另一个值
python3中/表示除法，结果包含小数，//才表示向下取整，求商

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 关于单链表，就是有很多单个的结点构成的，关于访问单链表，只需要知道头结点就可以了，使用循环会自动找后面的结点，这里不需要我们写如何把整数存入单链表的过程，只需要访问进行计算就可以了。
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 首先设置返回的结果链表的首节点
        result_head = ListNode(0)
        curr = result_head
        carry = 0
        while l1 != None or l2 != None:
            
            num1 = l1.val if l1!=None else 0
            num2 = l2.val if l2!=None else 0
            num3 = carry + num1 + num2
            carry = num3//10
            curr.next = ListNode(num3%10)
            # 给下一个结点赋计算出来的余数，是因为最后返回的也是从哑巴结点的下一个结点开始返回
            curr = curr.next
            if l1 != None:
                l1 = l1.next
            if l2 !=None:
                l2 = l2.next
        
        if carry>0:
            curr.next = ListNode(carry)
        
        return result_head.next      

```