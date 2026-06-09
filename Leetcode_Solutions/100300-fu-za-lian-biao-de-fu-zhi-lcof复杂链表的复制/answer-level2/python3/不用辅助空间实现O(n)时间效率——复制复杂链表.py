### 解题思路
剑指offer上给的第三种方法：
第一步根据原始链表的每个节点N创建对应的N'；将其连接在N的后面
第二步设置复制出来的节点N'的random指向，指向N的random的后一个节点
第三步将长链表分成两个链表，原始链表和复制链表


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
            return None
        temp = head
        while temp:      #### 第一步根据原始链表的每个节点N创建对应的N'；将其连接在N的后面     
            new_node = Node(temp.val)
            new_node.next = temp.next
            temp.next = new_node
            temp = new_node.next
        temp = head
        while temp:     #### 第二步设置复制出来的节点N'的random指向，指向N的random的后一个节点
            if temp.random:
                temp.next.random = temp.random.next
            else:       ## 如果N的random指向Null,则N’的random指向Null
                temp.next.random = None
            temp = temp.next.next
            
        new_head = head.next
        temp1 = head
        temp2 = new_head
        while temp1 and temp2:    ##第三步将长链表分成两个链表，原始链表和复制链表
            temp1.next = temp1.next.next
            temp1 = temp1.next
            if temp2.next: 
                temp2.next = temp2.next.next
            else:
                temp2.next = None
            temp2 = temp2.next
        return new_head
```