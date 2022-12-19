```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        '''
        思路，BFS(node,level),level表示当前节点的层次，然后用前序递归遍历，将遍历到的节点加入到
        对应的层即可！
        '''
        levels = []
        if root == None:
            return levels
        def BFS(node,level):
            # 如果当前节点是最新的一层，则levels增加一层
            if len(levels)-1 < level:
                levels.append([])
            levels[level].append(node.val)
            if node.left:
                BFS(node.left,level+1)
            if node.right:
                BFS(node.right,level+1)
        BFS(root,0)
        return levels
            
```
