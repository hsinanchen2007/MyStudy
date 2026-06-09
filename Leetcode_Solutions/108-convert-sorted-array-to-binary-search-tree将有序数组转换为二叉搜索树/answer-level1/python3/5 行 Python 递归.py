```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if nums:
            m = len(nums) // 2
            r = TreeNode(nums[m])
            r.left, r.right = map(self.sortedArrayToBST, [nums[:m], nums[m+1:]])
            return r
```
- 平衡二叉搜索树需要保证俩点：
	- 根节点大于左子树任意节点，小于右子树任意节点
	- 左右子数高度相差不超过 1
- 由以上性质，一个可行的递归条件可以得出：
	- 每次返回的根节点处于数组中间，以其左右半数组分别递归构造左右子树
	- 那么就意味着左子小于根，右子大于根，且所有节点左右子树节点数相差不超过 1 （由于递归的构树方式相同，所有节点都满足高度平衡）