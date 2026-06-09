这题是很经典的递归方法的应用题
首先 二叉搜索树是每个结点的左孩子都比他小，右孩子都比他大，这和我们的有序数组的排法简直不谋而合
这样我们就可以发现，这个有序数组的正中间的数一定是根节点，他左边的数字一定是他的左边孩子们，他右边的数字一定是他的右边孩子们
这样我们一层一层递归，找出左孩子们的根节点，右孩子们的根节点，直到没有数
所以递归算法代码为:

```
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        root = TreeNode(nums[len(nums)//2],None,None)
        root.left = self.sortedArrayToBST(nums[:len(nums)//2])
        root.right = self.sortedArrayToBST(nums[len(nums)//2+1:])

        return root
```
