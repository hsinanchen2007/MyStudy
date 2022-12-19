题目不是很难，递归调用。

```
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        if len(nums)==0:
            return None
        maxVal=max(nums)
        ind=nums.index(maxVal)
        p=TreeNode(maxVal)
        p.left=self.constructMaximumBinaryTree(nums[:ind])
        p.right=self.constructMaximumBinaryTree(nums[ind+1:])
        return p
```
