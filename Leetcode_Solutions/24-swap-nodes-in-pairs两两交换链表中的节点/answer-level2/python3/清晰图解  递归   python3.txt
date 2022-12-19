### 解题思路

直接上图

![梁欢.jpg](https://pic.leetcode-cn.com/b027ce30a0aa79486a789b11e5eb6abb7935dd1f6fe76d7c9c9a1c68e9b782c2-%E6%A2%81%E6%AC%A2.jpg)

如果当前head为None或者head.next为None，就不需要继续进行了，因为从head之后将不会有交换操作，直接返回head
先用N存下当前head的next
然后head.next.next指向后面用递归算出来的链表
把N的next指向当前head节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        N = head.next
        head.next = self.swapPairs(N.next)
        N.next = head
        return N
        
```