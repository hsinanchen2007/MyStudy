### 解题思路
队列记录所有待搜索节点，以及对应步数，知道找到两个子节点均为空。简单的是不用记录已经遍历的点。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        nodelist = [(root,1)]
        while nodelist:
            curnode, step = nodelist.pop(0)
            if curnode.left == None and curnode.right == None:
                return step
            if curnode.left != None:
                nodelist.append((curnode.left,step+1))
            if curnode.right != None:
                nodelist.append((curnode.right,step+1))

```