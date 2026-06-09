### 关键思路
遍历所有节点，序列化节点后的值为key，此节点出现次数为value，当value为2，将此节点存入结果列表。
### 解题代码
迭代
```python
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.hash = None

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        if root:root.hash=None
        self.rst,self.visited = [],{}
        stack = root and [root]
        while stack:
            i=stack.pop()
            if isinstance(i,tuple):
                i[1].hash = ' '.join([i[0],i[1].left.hash if i[1].left else 'n',i[1].right.hash if i[1].right else 'n'])
                self.visited[i[1].hash]=self.visited.get(i[1].hash,0)+1
                if self.visited[i[1].hash]==2:self.rst.append(i[1])
            if isinstance(i,precompiled.treenode.TreeNode):
                stack.append((str(i.val),i))
                stack.append(i.left)
                stack.append(i.right)
        return self.rst
```
递归
```python
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        self.rst = []
        self.visited = {}
        def fds(node):
            if node==None:
                return 'n'
            l_hash = fds(node.left)
            r_hash = fds(node.right)
            n_hash = str(node.val)+'_'+l_hash+'_'+r_hash            
            self.visited[n_hash] = self.visited.get(n_hash,0)+1            
            if self.visited[n_hash]==2:self.rst.append(node)                
            return n_hash
        fds(root)
        return self.rst
```