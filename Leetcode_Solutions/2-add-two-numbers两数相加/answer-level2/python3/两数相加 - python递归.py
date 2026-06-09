# 两数相加

## 题目
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

## 示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

## 分析
l1、l2可能有空值
l1、l2的next可能有空值
处理进位

###思路
处理当前节点：
    l1, l2可能有空值：交换l1, l2，使l1必有值，l2可能有值
    若l2为空
        1. 若无需进位，直接返回l1
        2. 若需要进位：使其变为0节点，以便减少后面的判断
处理next节点：
    l1, l2的next可能有空值，处理进位
        1. 都为空
            1.1 无进位：l.next=None
            1.2 有进位：l.next=ListNode(1)
        2. 都有值
            交由递归处理
        3. l1, l2其中一个next有值
            3.1 有进位：交由递归处理
            3.2 无进位：*使用or关键字* -> 直接使l.next=有值的next

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 默认不传入两个None值
        if l1==None:
            l1, l2 = l2, l1
        if l2==None:
            if l1.val < 10:
                return l1
            else:
                l2 = ListNode(0) # 便于后面使用，减少if数量

        val= l1.val + l2.val
        l, carry = ListNode(val%10), int(val/10)

        if l1.next==l2.next==None:
            l.next = ListNode(carry) if carry else None
        elif l1.next!=None and l2.next!=None:
            l1.next.val += carry
            l.next = self.addTwoNumbers(l1.next, l2.next)
        else: # l1, l2其中一个next为None
            if not carry:
                l.next = (l1.next or l2.next)
            if carry:
                (l1.next or l2.next).val += carry
                l.next = self.addTwoNumbers((l1.next or l2.next), None)
        return l
```
