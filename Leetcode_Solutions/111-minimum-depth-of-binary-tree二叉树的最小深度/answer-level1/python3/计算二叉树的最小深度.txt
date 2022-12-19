### 解题思路
三种方法：
1.递归:需要注意你此时是要求树的最小深度，最小深度是指从根节点到最近叶子节点的最短路径上的节点数量，所以在递归时，需要先判断这个节点的子树是否存在，如果有一边子树不存在，需要在另外一边子树去找。而最大深度因为求得是最大值，所以不需要判断这个
2.DFS和BFS
这两个区别仅在于DFS用stack，BFS用queue，另外时间复杂度上DFS要遍历每个节点，所以DFS时间复杂度为O(N)，并且DFS需要多mantain一个变量记录最小深度，遍历每一个节点时去比较，判断是否需要更新。而BFS不需要，它是每一层依次判断，当在某一层找到叶子节点后直接返回对应的深度，BFS的时间复杂度最坏情况下是树平衡，除了最后一层节点之外，上面的每一层都要去访问，这样访问了 N/2 个节点，因此复杂度是O(N)。


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
    def minDepth(self, root: TreeNode) -> int:
        if(not root):return 0
        if(not root.left):return self.minDepth(root.right)+1
        if(not root.right):return self.minDepth(root.left)+1
        return min(self.minDepth(root.left),self.minDepth(root.right))+1
#BFS
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if(not root):return 0
        queue = deque([(1,root)])
        while(queue):
            depth,node=queue.popleft()
            if(not node.left and not node.right):return depth
            if(node.left):queue.append((depth+1,node.left))
            if(node.right):queue.append((depth+1,node.right))
#DFS
    def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        stack = [(1, root)]
        min_depth = float('inf')
        while stack:
            depth, node = stack.pop()
            if not node.left and not node.right:
                min_depth = min(min_depth, depth)
            if node.right:
                stack.append((depth + 1, node.right))
            if node.left:
                stack.append((depth + 1, node.left))       
        return min_depth 
```