
思路：
1. 平衡二叉搜索树的特点是：每个节点的左右子树都高度差在1以内，每个节点左子树小于右子树。
2. 根据平衡二叉搜索树的特点，可以联想到，每个节点当做根节点的时候，左子树形成的数组一定比它小，右子树形成的数组一定比他大。
因此，符合有序数组任意子数组中点的性质。
3. 结合树结构常用的递归思想，可以采用DFS，递归构建这颗树，为了实现每个节点都是平衡二叉搜索树，可以递归二分数组来分配资源，
左面的构建左子树，右面的构建右子树，以此递归。

```
def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if nums is None:
            return None
        begin = 0
        end = len(nums) - 1
        if begin > end:
            return None
        mid = (begin + end) >> 1
        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[begin:mid])
        root.right = self.sortedArrayToBST(nums[mid+1:end+1])
        return root
```

