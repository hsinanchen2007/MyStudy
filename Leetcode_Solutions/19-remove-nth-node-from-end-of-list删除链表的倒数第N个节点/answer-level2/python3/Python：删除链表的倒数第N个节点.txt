### 解题思路
方法一：递归
一次遍历，要找到倒数的一个序号：第一反应——递归，它的所有操作都是从最后一次嵌套开始的，所以这个计数用递归是最顺溜的思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        global count
        if head is None:
            count=0
            return None
        head.next=self.removeNthFromEnd(head.next,n)
        count+=1
        return head.next if n==count else head 
```

### 解题思路
方法二：双指针
参考官方解题，很巧妙的方法，两个指针正好卡要找节点的序数

### 代码
```python3
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        node=ListNode(-1)
        node.next=head
        first=second=node
        for i in range(n):
            first=first.next
        while first.next:
            first=first.next
            second=second.next
        second.next=second.next.next
        return node.next
```