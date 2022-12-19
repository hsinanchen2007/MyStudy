### 解题思路
就每次递归减去当前节点的值，要注意的是要判断当前节点是否是叶子节点
![TIM截图20191220125446.jpg](https://pic.leetcode-cn.com/32c0e625a95f19c5ceb6656f9eb17eec80f5890cd90f7dbd5b1b716e5cb5428c-TIM%E6%88%AA%E5%9B%BE20191220125446.jpg)
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
        if root is None:
            return False
        return self.PathSum(root,sum)
    
    def PathSum(self, root: TreeNode, sum: int) -> bool:
        if root == None:
            return False
        sum = sum - root.val
        if sum == 0 and (root.left == None and root.right == None) :
            return True

        return self.PathSum(root.left,sum ) or self.PathSum(root.right,sum)
```