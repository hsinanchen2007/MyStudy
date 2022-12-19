```
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        
        def mktree(nums):
            if not nums:
                return None
            n = TreeNode(max(nums))
            i = nums.index(n.val)
            n.left = mktree(nums[:i])
            n.right = mktree(nums[i+1:])
            return n
        return mktree(nums)
```
迭代法直接构造最大树
```
class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return None
        root = TreeNode(nums[0])
        for i in range(1, len(nums)):
            n = TreeNode(nums[i])
            if n.val>root.val:
                n.left = root
                root = n
            else:
                m = root
                p = root
                while m and m.val>n.val:
                    p = m
                    m = m.right
                n.left = m
                p.right = n
        return root
                    
```

