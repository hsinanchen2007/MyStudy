### 解题思路
用一次深度优先搜索来遍历所有的节点，同时将该节点的上下界限传递进去，时间复杂度O(N)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        #思路：递归？
        #由于是二叉搜索树，还得加一个上下限
        ans = True
        def dfs(node,up= float('inf'),down=float('-inf')):
            nonlocal ans
            if not ans:
                return 
            if node == None:
                return 
            if node.left:
                if node.left.val <=down or node.left.val >= node.val:
                    ans = False
                    return 
            if node.right :
                if node.right.val <= node.val or node.right.val >= up:
                    ans = False
                    return 
            dfs(node.left,up = node.val,down = down)
            dfs(node.right,up = up,down = node.val)
        dfs(root)
        return ans


        
```