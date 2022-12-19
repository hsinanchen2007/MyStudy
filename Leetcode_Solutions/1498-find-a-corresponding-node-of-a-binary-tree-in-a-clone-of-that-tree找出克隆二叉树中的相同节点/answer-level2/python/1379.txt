### 解题思路
1、特殊情况：None，original = target
2、遍历左子树、右子树
3、遍历左子树结果为None，返回右子树遍历返回结果；遍历右子树结果为None，返回左子树遍历返回结果

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        if original == None:
            return None
        if original == target:
            return cloned
        result_left, result_right = None, None
        if original.left != None:
            result_left = self.getTargetCopy(original.left, cloned.left, target)
        if original.right != None:
            result_right = self.getTargetCopy(original.right, cloned.right, target)
        if result_left == None:
            return result_right
        if result_right == None:
            return result_left

```