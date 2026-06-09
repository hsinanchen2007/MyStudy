### 解题思路
1.递归:注意二叉树的深度为根节点到最远叶子节点的最长路径上的节点数(与最小深度的区别是最近与最远),这也是为什么最小深度递归时需要多判断子树是否为空，可以随时return，而最大深度递归可以直接一行代码搞定
2.BFS
注意最大深度的BFS不需要判断某一层是否有叶节点，有的话直接返回(这是最小深度需要的)，最大深度的BFS是需要遍历每一层，遍历每一层时，某个节点只要有子节点就把它enqueue进去，直至遍历到最后一层
所有节点都要遍历，时间复杂度为O(N),所有节点都要出入队列，空间复杂度为O(N)。
3.DFS
queue变成stack，需要多mantain一个变量记录最大深度，遍历每一个节点时去比较，判断是否需要更新。所有节点都要遍历，时间复杂度为O(N),所有节点都要出入栈，空间复杂度为O(N)。
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
#递归
    def maxDepth(self, root):
        return max(self.maxDepth(root.left) , self.maxDepth(root.right) ) + 1 if root else 0
#BFS
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        # initialize the queue and lenth
        queue = collections.deque()
        queue.append(root)
        lenth = 0
        
        # loop over the queue 
        while queue:
            lenth += 1
            for i in range(len(queue)):
                # print("lenth:{}, i:{}".format(lenth, i))
                node = queue.popleft()
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
        
        return lenth
#DFS
    def maxDepth(self, root: TreeNode) -> int:    
        # DFS
        if root is None:
            return 0
        stack = [(1, root)]
        depth = 0
        while stack:
            cur_dep, node = stack.pop()
            depth = max(depth, cur_dep)
            if node.right:
                stack.append((cur_dep+1,node.right))
            if node.left:
                stack.append((cur_dep+1,node.left))
        return depth
```