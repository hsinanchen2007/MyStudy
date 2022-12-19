### 解题思路
递归，每次找出最大二叉树的根节点，划分左右子树

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums)==0:
            return None
        
        root = TreeNode(max(nums))
        ix = nums.index(root.val)

        root.left = self.constructMaximumBinaryTree(nums[:ix])
        root.right = self.constructMaximumBinaryTree(nums[ix+1:])

        return root
```