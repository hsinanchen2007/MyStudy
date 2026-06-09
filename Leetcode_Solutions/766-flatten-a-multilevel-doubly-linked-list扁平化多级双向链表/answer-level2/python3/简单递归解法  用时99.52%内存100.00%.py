### 解题思路
![image.png](https://pic.leetcode-cn.com/4a0b4e61b26c1c8cac1fe1c128f62841e45bc53c2b02f40e297ccbb6ba38cf24-image.png)
简单的递归方法


### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        dummy = Node(0, None, head, None)
        self.helper(dummy)
        pre = None
        while head :
            head.prev = pre
            head.child = None
            pre = head
            head = head.next
        return dummy.next
    
    def helper(self, head):
        # 函数返回排序完链表的最后一个节点
        if not head: return None

        dummy = Node(0, None, head, None)
        while head.next and not head.child:
        # 一直向后寻找、遇到child就停止
            head = head.next

        if head.child and not head.next:
        # 有child无next，next连到child上，并递归寻找child为起点排序后的最后一个节点
            head.next = head.child
            return self.helper(head.next)

        elif head.child:
        # 说明有child有next，next接在child为排序完的最后节点之后，并对next进行递归
            end = self.helper(head.child)
            temp = head.next
            head.next = head.child
            end.next = temp
            return self.helper(temp)
        # 说明没child没next，head已经为最后的节点
        else: return head
        

```