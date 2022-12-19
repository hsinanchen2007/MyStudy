### 解题思路
这道题的难点在于没法通过一次遍历就完成对复杂链表的复制，因为random指针可能指向后面的节点，而后面的节点还没有生成，所以无法对random指针进行赋值，而我们可以分成两次遍历完成这件事：
（1）先对单链表进行赋值（不对random指针赋值）并生成节点哈希表，即原始节点和新节点的字典；
（2）重新遍历链表根据哈希表对新链表的random指针进行赋值。

### 代码

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if head is None:
            return None
        node_dict = {}
        # 先生成所有节点，并用next指针连接起来
        p = head
        q = new_head = Node(head.val)
        node_dict[p] = q
        while p.next:
            new_node = Node(p.next.val)
            node_dict[p.next] = new_node
            q.next = new_node
            p = p.next
            q = q.next
        # 给新节点的random指针赋值
        p = head
        q = new_head
        while p:
            if p.random:
                q.random = node_dict[p.random]
            p = p.next
            q = q.next
        return new_head
```