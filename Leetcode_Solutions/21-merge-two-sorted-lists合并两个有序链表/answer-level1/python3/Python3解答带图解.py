### 解题思路
两个形参l1和l2是两个有序链表的头结点，可以当成是指针来用，利用这两个节点进行迭代。
先比较l1和l2的value（即data值部分），如果l1的值小于l2的值，则l1保持不变，l1.next在原来的l1.next和l2中间选，哪个小，哪个就是新的l1.next，由此迭代；如果l2的值小于l1的值，同理。

![12.PNG](https://pic.leetcode-cn.com/10b05c86b8f5b0de692801b67915df658594e63fd7ff4a2585aa51cc29ea0f03-12.PNG)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:  # l1 or l2 is null 
            return l2
        elif l2 is None:
            return l1
        else:
            if l1.val < l2.val:
                l1.next = self.mergeTwoLists(l1.next, l2)  # iteration
                return l1
            else:
                l2.next = self.mergeTwoLists(l1, l2.next)
                return l2






        
```