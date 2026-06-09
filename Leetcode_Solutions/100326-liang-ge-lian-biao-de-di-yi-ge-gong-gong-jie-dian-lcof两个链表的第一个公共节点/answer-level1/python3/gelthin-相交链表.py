### 解题思路
[主站 160 题相同](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)
有多种解法，主站习题用的解法是把两条链表拼在一起，然后双指针每次走1， 总会相遇。

我这里的解法是阿里面试题，从带有父节点的二叉树的两个节点寻找最近公共父节点衍生而来。
快慢指针，首先计算出来两个节点到最后的父节点的距离，然后一个节点走一段这个距离，然后两个节点同时走。

但当时代码写的一塌糊涂，非常不好。



### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        p1, p2 = headA, headB
        
        n1 = 0 # 节点个数
        while p1:
            n1 += 1
            p1 = p1.next
        
        n2 = 0
        while p2:
            n2 += 1
            p2 = p2.next
        
        if n1 > n2:  # 让 p2 代表长链表
            p1, p2 = headB, headA
        else:
            p1, p2 = headA, headB
        
        for _ in range(abs(n2-n1)):
            p2 = p2.next
        while p1 and p2 and p1 != p2: # p1 可能为 None
            p1 = p1.next
            p2 = p2.next
        return p1
```