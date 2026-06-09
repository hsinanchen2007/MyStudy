### 解题思路
2020.3.16 面试题

带有父节点的二叉树寻找第一个公共节点可以化为此题。
此题还有另一种解法，分别计算出两个链表的总长度，设为 n1, n2
然后长的那个链表先走 abs(n2-n1) 步，然后两个链表同时走，每走一步就判断一下是否所指向的节点是否相同。

#### 这种链表题，经常输入输出比较精巧。
题目描述中给的输入不等于解答算法的函数的输入，

题目描述中的输入通常是为了能够唯一确定一个给定的测试样例，便于仔细地剖析来看。
而这些输入中的有一些是不能够使用的。
有好几题是这个样子，例如，一些链表题目。

#### 把两个链表拼接起来， a+b， 这个想法也常用
这一题，参考了官方题解，第三种解法非常巧妙。 两段路都跑一遍。使得两个指针所跑过的路一样多。

A = a + m
B = b + m

构造两段相同长度的路，  a+m+b+m,  b+m+a+m, 由于 a+m+b = b+m+a, 故两者会在最后一个 m 的开始处相遇。
如果 m 为空，最终 p1 = None, p2 = None

具体的图解可以看另一个高分题解。



### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if (None==headA) or (None==headB):
            return None
        a, b = headA, headB
        while a != b:
            a = a.next if a != None else headB
            b = b.next if b != None else headA
        if a == None:
            return None
        else:
            return a
```