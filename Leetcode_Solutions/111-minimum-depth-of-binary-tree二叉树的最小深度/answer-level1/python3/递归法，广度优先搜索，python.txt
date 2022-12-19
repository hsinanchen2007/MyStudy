**1.递归写法**

四个出口条件：
1.此时参数为None，返回0即可，表示并不增加深度
2.左子树节点为空，返回右子节点的最小深度+1。为什么不返回0，因为此时这个节点可能不是叶子节点，还要考察右子树节点
3.右子树节点为空，返回左子节点的最小深度+1。
4.左右子树都有节点，那么返回左右子树中的最小深度，并且+1

```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if(not root):return 0
        if(not root.left):return self.minDepth(root.right)+1
        if(not root.right):return self.minDepth(root.left)+1
        return min(self.minDepth(root.left),self.minDepth(root.right))+1
```


2.广度优先搜索


```
from collections import deque
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if(not root):return 0
        queue = deque([(1,root)])
        while(queue):
            depth,node=queue.popleft()
            if(not node.left and not node.right):return depth
            if(node.left):queue.append((depth+1,node.left))
            if(node.right):queue.append((depth+1,node.right))

```
