### 解题思路

题解我是看别人的答案，但是这种方法我觉得是最容易理解，不容易绕。
1， 建立一个map， key值是原先链表里的node ， value值是new出来的node，
    所以要先把循环一遍，把所有节点都先new出来。next、random先留空。
2， 等map建立好之后，就是连接next、random。
    如果要给一个新的node连接next，那么这个新node.next必须也应该是一个new出来的node，
    那么怎么对应呢？还是通过map里找，因为旧node.next如果是一个节点的话，那么旧node.next肯定也是在map的keys里。
    仔细想想是不是这么回事。
    所以有：
    lookup[node].next = lookup.get(node.next)
    **注意**
    这里只能写作 lookup[node].next = lookup.get(node.next)
    不能写作 lookup[node].next = lookup[node.next] , 
    因为如果node.next为空，这里就会报错了，你可以试试看
    random同理。

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
        if head == None:
            return None
        
        lookup = {}

        node = head
        while node != None:
            lookup[node] = Node(node.val , None , None)
            node = node.next
        
        node = head

        while node != None:
            lookup[node].next = lookup.get(node.next)
            lookup[node].random = lookup.get(node.random)
            node = node.next

        return lookup[head]
```