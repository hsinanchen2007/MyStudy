### 递归
先序遍历，递归左右子树，理解起来还是比较简单的。代码如下：
```
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        nums1 = []
        nums2 = []
        def leaf(root,nums):
            if root and not root.left and not root.right:
                nums.append(root.val)
            if root.left:
                leaf(root.left,nums)
            if root.right:
                leaf(root.right,nums)
            return nums
        return leaf(root1,nums1) == leaf(root2,nums2)
        
```
#### 复杂度分析
时空复杂度都是O(m+n)