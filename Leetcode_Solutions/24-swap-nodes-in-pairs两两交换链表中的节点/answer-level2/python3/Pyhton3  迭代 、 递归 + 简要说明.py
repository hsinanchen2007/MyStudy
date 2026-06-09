一、Clarification

目标明确两两交换链表中的节点，无特别需要注意的边界但需常规关注下空链表和只有一个元素的链表

二、Possible solutions

1、迭代

在边界内同时取出2个节点并交换，然后向下移动2位，使用哨兵简化处理，空链表，一个元素的链表

2、递归

递归终止条件 head 和 head.next 为None，每层递归交换当前两节点，并返回 交换后两个节点中的前一个节点

迭代实现

```python
#@author:leacoder
#@des: 循环实现  多元赋值
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        pre = ListNode(None) # 哨兵
        retult,pre.next =pre, head
        while pre.next and pre.next.next:
            a = pre.next
            b = pre.next.next  # 记录 要交换的两节点
            pre.next,b.next,a.next,= b,a,b.next # 2个节点交换,注意哨兵的next改变了
            pre = a # 向下移动2位
        return retult.next
```

递归实现

```python
#@author:leacoder
#@des: 递归实现  多元赋值

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        resultmp = self.swapPairs(head.next.next) # 下移两位  返回 值为两两交换后  两个节点中的前一个节点
        # 交换 当前两节点
        A, B = head, head.next # 当前两节点
        A.next, B.next = resultmp,A # 交换
        return  B   # 返回 两两交换后  两个节点中的前一个节点
```