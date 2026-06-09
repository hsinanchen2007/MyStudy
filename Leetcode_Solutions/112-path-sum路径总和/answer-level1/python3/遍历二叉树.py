### 解题思路
遍历二叉树，计算总和，考虑左右节点非空，左右节点有一个为空和左右节点均为空（即叶子节点的情况：需要返回,return即可，用flag标记是否有和=sum的情况）

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        def traverse(node, ssum):
            global flag
            if node.left == None and node.right == None:
                if ssum + node.val == sum:
                    flag = True
                    return 
                else:
                    return 
            if node.left != None and node.right != None:
                ssum += node.val
                traverse(node.left, ssum)
                traverse(node.right, ssum)
            if node.left != None and node.right == None:
                ssum += node.val
                traverse(node.left, ssum) 
            if node.left == None and node.right != None:
                ssum += node.val
                traverse(node.right, ssum) 
        if root == None:
            return False
        ssum = 0
        global flag 
        flag = False
        traverse(root, ssum) 
        return flag  


    
```