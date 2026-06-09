### 解题思路
第一步：遍历原链表所有节点，一一复制新节点并连接，同时建立原节点和新节点之间的映射
第二步：再次遍历原链表建立random指针关系
时间复杂度：O(n),空间复杂度：O(n)
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
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return head
        
        p1=head
        p2=Node(0)
        tmp=p2
        hashmap={}
        while p1:
            p2.next=Node(p1.val)
            p2=p2.next
            hashmap[p1]=p2
            p1=p1.next
        
        p3=head
        while p3:
            if p3.random:
                node1=hashmap[p3]
                node2=hashmap[p3.random]
                node1.random=node2
            p3=p3.next
        
        return tmp.next
```