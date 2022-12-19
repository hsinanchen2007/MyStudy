### 方法一：影子法

* 复制链表容易，问题的关键是怎么复制`random`指针。
* 这里采用影子法(姑且称之！)
    * step1: `A->B->C`double成`A->A'->B->B'->C->C'`，其中`A' B' C'`复制了`A B C`的`val`和`next`
    * step2: `A' B' C'`copy`A B C`的`random`指针。这里潜在的原理是：`A`是`A'`的前一节点，而`A'`的`random`指向的节点也是`A'`的`random`指向的前一节点。
    * step3: 把复合链表`A->A'->B->B'->C->C'`拆成`A->B->C`和`A'->B'->C'`，返回`A'->B'->C'`
* 时间复杂度: O(N); 空间复杂度: O(1)，除要返回的链表外。

```python []
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
        if head is None:
            return None
        # step1: double all nodes with val and next
        curr = head
        while(curr):
            temp = curr.next
            newNode = Node(curr.val)
            curr.next = newNode
            newNode.next = temp
            curr = temp
        # step2: get random pointer for all new nodes
        curr = head
        while(curr):
            curr_copy = curr.next
            if curr.random is not None:
                curr_copy.random = curr.random.next
            curr = curr.next.next
        # step3: split into 2 lists
        curr = head
        dummy = Node(0)
        prev = dummy
        while(curr):
            prev.next = curr.next
            curr.next = curr.next.next
            prev = prev.next
            curr = curr.next
        return dummy.next
```
### 方法二：递归(图的dfs)+哈希

* 哈希表`visitedHash`存的是`old_node->new_node`的映射。
* base case: 已有该节点的拷贝，返回该拷贝
* iterative case: 对于该节点`head`，新建节点`node`。`node`的`val`和`head`相同; `node`的`next`和`random`相应的是`head`的`next`和`random`的拷贝。
* 时间复杂度: O(N); 空间复杂度: O(N)，哈希表和堆栈帧。

```python []
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def __init__(self):
        self.visitedHash = {}

    def copyRandomList(self, head: 'Node') -> 'Node':
        if head == None:
            return None

        if head in self.visitedHash:
            return self.visitedHash[head]

        node = Node(head.val, None, None)
        self.visitedHash[head] = node

        node.next = self.copyRandomList(head.next)
        node.random = self.copyRandomList(head.random)

        return node

```
### 方法三：迭代（图的bfs）+哈希

* 方法二的思路是：先解决完所有的`next`，再解决`random`。如果看成图的话，是用递归写成的dfs算法。
* 有dfs的地方就有bfs，方法三的思路是，解决完该节点的`next`和`random`，再解决下一个节点。
* 时间复杂度：O(N); 空间复杂度：O(N), 哈希表。

```python []
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def __init__(self):
        self.visitedHash = {}

    def copyRandomList(self, head: 'Node') -> 'Node':
        def copyNode(node):
            if not node:
                return None
            if node in self.visitedHash:
                return self.visitedHash[node]
            node_copy = Node(node.val)
            self.visitedHash[node] = node_copy
            return node_copy

        curr = head
        curr_copy = copyNode(head)

        while(curr):
            curr_copy.next = copyNode(curr.next)
            curr_copy.random = copyNode(curr.random)
            curr = curr.next
            curr_copy = curr_copy.next

        return self.visitedHash[head]
```

### 方法四：调库

* 看到别的童鞋(@SherryOKOK)的题解，深感敬佩。

```python []
import copy
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        return copy.deepcopy(head)
```