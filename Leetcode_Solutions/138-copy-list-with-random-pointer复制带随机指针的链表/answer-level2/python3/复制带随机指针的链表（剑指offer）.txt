### 解题思路
·剑·指· 原题，本题采用的解法见代码

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    """
    ***原题，上有更详细的解答；
    解题思路：1. 遍历链表，在遍历的时候，将每个节点的深拷贝插入到当前节点与下一个节点之间，即最后形成：node1->copy_of_node1->node2->copy_of_node2->...->noden->copy_of_noden
    2. 拷贝随机指针：copy_of_nodek.random=nodek.random.next
    3. 最后将深拷贝的链表和原链表还原
    """
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return head
        
        # 遍历链表，构造node1->copy_of_node1->node2->copy_of_node2->...->noden->copy_of_noden的链表结构
        start = head
        while head:
            tmp = Node(head.val)
            head_next = head.next
            head.next, tmp.next = tmp, head_next
            head = head_next
        # 完成random指针的复制
        head = start
        while head:
            if head.random:
                head.next.random = head.random.next
            else:
                head.next.random = None
            head = head.next.next
        # 将链表拆分成两个链表：原来的与深拷贝之后的
        head1 = start
        head2 = head = start.next
        while head1:
            head1.next = head1.next.next
            if head2.next:
                head2.next = head2.next.next
            else:
                head2.next = None
            head1, head2 = head1.next, head2.next
        
        return head
```