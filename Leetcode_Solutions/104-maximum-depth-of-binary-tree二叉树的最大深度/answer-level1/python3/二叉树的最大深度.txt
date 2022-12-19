- **思路**

1)递归：根节点对应的最大深度是左右子树最大深度的最大值加一。

2）广度优先搜索： 广度优先搜索最后到达的叶子节点的是最大深度。

3）深度优先搜索：记录各节点的深度，通过访问到的叶子节点的深度更新max，直到遍历完成。

- **实例**

递归：
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        return 1+ max(self.maxDepth(root.left), self.maxDepth(root.right))

```
广度优先搜索：
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        queue = []
        queue.append(root)
        level = 0
        
        while queue:
            level += 1
            num = len(queue)
            for i in range(num):
                node = queue.pop(0)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
        return level
```
深度优先搜索：

```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        
        self.max_level = 1
        self._dfs(root,1)
        return self.max_level
        
    def _dfs(self, node, level):
        if not node: return  
        if level > self.max_level: self.max_level = level
        
        self._dfs(node.left, level + 1)
        self._dfs(node.right, level + 1)  
```

- **结果**

递归：

执行用时 : 72 ms, 在Maximum Depth of Binary Tree的Python3提交中击败了56.36% 的用户</br>
内存消耗 : 14.9 MB, 在Maximum Depth of Binary Tree的Python3提交中击败了86.22% 的用户

广度优先搜索 BFS:

执行用时 : 64 ms, 在Maximum Depth of Binary Tree的Python3提交中击败了91.02% 的用户</br>
内存消耗 : 14.4 MB, 在Maximum Depth of Binary Tree的Python3提交中击败了95.60% 的用户

深度优先搜索 DFS：

执行用时 : 52 ms, 在Maximum Depth of Binary Tree的Python3提交中击败了99.56% 的用户</br>
内存消耗 : 15.2 MB, 在Maximum Depth of Binary Tree的Python3提交中击败了85.40% 的用户