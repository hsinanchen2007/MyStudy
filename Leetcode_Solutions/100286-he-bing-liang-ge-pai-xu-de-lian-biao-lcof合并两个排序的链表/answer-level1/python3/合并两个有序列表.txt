### 解题思路
## 思路一：迭代
依次比较两个链表头节点的大小，将较小的一个添加到新的链表里。
**重点**是使用两个指针分别指向两链表的头节点，可以直接用l1和l2迭代；对于新的链表：应该定义一个伪头节点和一个指针指向新链表的尾节点，进行迭代的是尾节点，最后返回的是伪头节点的next。

#### Tips：
1. 特殊情况的处理：空链表

### 代码：

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        h = ListNode(0)
        result = h

        while l1 and l2:
            if l1.val >= l2.val:
                h.next = l2
                l2 = l2.next
            else:
                h.next = l1
                l1 = l1.next
            h = h.next
        
        h.next = l1 if l1 else l2
        
        return result.next

```


时间复杂度：O(N)
空间复杂度：O(1)


## 思路二：递归
每次递归需要输入当前两链表的头节点。
**重点**是新链表中新节点的添加，而新节点是下一次递归的返回值。递归的结束条件是：某一链表为空，此时返回另一链表的剩余部分。

### 代码：

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        
        if l1.val >= l2.val:
            l2.next = self.mergeTwoLists(l1,l2.next)
            return l2
        else:
            l1.next = self.mergeTwoLists(l1.next,l2)
            return l1

```

时间复杂度：O(N)
空间复杂度：O(1)

