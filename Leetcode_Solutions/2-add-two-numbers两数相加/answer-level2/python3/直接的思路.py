### 解题思路
此处撰写解题思路
其实这个题目很简单，但是呢要又快又准确可能需要一点功力，另外，题目里面要求使单链表。
我的思路很简单直接，就是我们平时做计算的过程。
中间我遇到了一个问题，就是没有头指针怎么返回，解决思路借鉴了别人，创造一个头结点，返回它的next。
### 代码

```python
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # 指针 i j
        i = l1
        j = l2
        # 进位
        carry = 0
        # 头结点
        headNode = ListNode(0)
        # 指针k
        k = headNode

        # partI : 计算相同长度部分
        while i != None and j != None:
            # 计算 进位，value
            value = i.val + j.val + carry
            carry = 0
            if value >= 10:
                value = value - 10
                carry = 1

            # 新建节点
            n = ListNode(value)

            # 链接节点
            k.next = n

            # 指针变换
            k = n
            i = i.next
            j = j.next

        # partII: 如果l1,l2长度不一致
        extra = i
        if i != None:
            extra = i
        if j != None:
            extra = j

        while extra != None:
            # 计算 进位，value
            value = extra.val + carry
            carry = 0
            if value >= 10:
                value = value - 10
                carry = 1

            # 新建节点
            n = ListNode(value)

            # 链接节点
            k.next = n

            # 指针变换
            k = n
            extra = extra.next

        # partIV: 多余进位
        if carry == 1:
            n = ListNode(1)
            k.next = n

        return headNode.next


```