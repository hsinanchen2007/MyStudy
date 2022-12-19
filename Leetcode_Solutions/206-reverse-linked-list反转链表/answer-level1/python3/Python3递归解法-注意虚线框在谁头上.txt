### 解题思路
链表是经典的递归定义的数据结构，链表相关的题目常常考察递归，翻转链表是其中的经典题目。
在思考递归问题的时候，我们要从上到下思考：
1. 子问题是什么
2. base case是什么
3. 在当前层要干什么
对翻转链表来说，以1->2->3->4->5为例：
1. 子问题是：除去current node，翻转剩余链表，即除去1, reverseList(2->3->4->5),递归得到的解是 5->4->3->2
2. base case:当前节点为空，返回空，当前节点的next为空（只剩余一个节点），返回该节点
3. 在当前层要干什么：翻转链表，即把1->2变为2->1.
最后return的是结果链表的头，也就是递归解的头。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        nextNode = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return nextNode
```