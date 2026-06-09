### 解题思路
- 先两遍循环，分别求解两个链表的长度l1，l2，则最大的交叉部分长度为insLength = min（l1， l2）-1，对应两个链表的第一个交叉节点为倒数第insLen个节点
- 两个链表分别先走到第一个可能的交叉节点，暂停
- 两个链表同步往下走，如果相等即为交叉节点，否则继续往下走

### 执行结果
![image.png](https://pic.leetcode-cn.com/1d91d32c3449911ecbae95484290a46340ed981fef4b60ba8d27a679d4b26828-image.png)


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None

        l1, l2 = 0, 0
        node1, node2 = headA, headB
        while node1:
            l1, node1 = l1+1, node1.next
        while node2:
            l2, node2 = l2+1, node2.next

        insLenght = min (l1, l2)
        node1, node2 = headA, headB
        for _ in range(l1 - insLenght):
            node1 = node1.next
        for _ in range(l2 - insLenght):
            node2 = node2.next
        
        while node1 and node2:
            if node1 == node2:
                return node1
            node1, node2 = node1.next, node2.next
        
        return None

```

### 复杂度
时间复杂度O（max（N，M）），空间复杂度O（1）