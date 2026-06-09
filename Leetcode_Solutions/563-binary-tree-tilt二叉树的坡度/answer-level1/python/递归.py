### 解题思路
首先明确一点：一个节点的坡度是指其左右子树**所有节点之和**的差值的绝对值
于是，我们得先求得所有节点之和，在这里我定义一个递归函数来求和。


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root: TreeNode) -> int:
        def sumval(root):   #求和函数，返回包括参数节点及其所有子节点数值之和
            if not root:
                return 0
            else:
                return root.val+sumval(root.left)+sumval(root.right)
        if not root:
            return 0
        l=sumval(root.left)  #左子树
        r=sumval(root.right) #右子树
        return abs(l-r)+self.findTilt(root.left)+self.findTilt(root.right) #依次自上而下进行递归

```