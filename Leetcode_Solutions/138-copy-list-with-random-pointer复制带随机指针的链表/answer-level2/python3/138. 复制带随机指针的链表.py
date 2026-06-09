### 解题思路
本题要实现一个简陋的深拷贝功能，难点在于如何取得random指针指向的对象的拷贝，下面代码通过维护一个原对象与拷贝对象的哈希表来解决这个问题。时间负责度为O(N)，空间复杂度为O(N)。

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
        def getNewNode(node):
            if node in old2new:
                return old2new[node]
            else:
                if node==None:
                    return None
                else:
                    newNode = Node(node.val,None,None)
                    old2new[node]=newNode
                    return newNode
        
        if not head:
            return head
        old2new = {}
        newHead = Node(head.val,None,None)
        old2new[head]=newHead
        curOldNode = head
        curNewNode = newHead
        while curOldNode:
            curNewNode.next = getNewNode(curOldNode.next)
            curNewNode.random = getNewNode(curOldNode.random)
            print(curNewNode.val)
            curOldNode=curOldNode.next
            curNewNode=curNewNode.next
        return newHead

```