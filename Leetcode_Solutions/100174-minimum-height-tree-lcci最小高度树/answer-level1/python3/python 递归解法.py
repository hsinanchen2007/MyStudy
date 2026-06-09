### 解题思路
首先，我们需要明确二叉搜索树的定义，从节点的值来看简单来说就是，左子树<根<右子树。

![二叉搜索树.jpg](https://pic.leetcode-cn.com/f84cb0ee8c94bc1cac6e48386bfb0b1aa83faf4ebb33a3880e7d4362df654f6f-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.jpg)

如上图所示，可以看到从根节点开始，具有左<根<右的特性。

然后我们需要理解题目中要求的"高度最小的二叉搜索树"这个概念，举例来说，下图的二叉搜索树就不符合高度最小的要求：

![举例.jpg](https://pic.leetcode-cn.com/ba99d1356f43eeac13aa521e93b15cca0039a7b197aa22645a8aafc2adf49d9f-%E4%B8%BE%E4%BE%8B.jpg)

实际上就是要求避免在最后一层之前出现空节点的情况。

通过二叉搜索树的定义，我们可以知道其根节点必然是有序整数序列的中位数，对于奇数来说，很自然地取到中位数，对于偶数实际上，取左或者取右都是可以的。

由于是有序整数，那么在找到根节点后，我们可以将数组一分为二，其左侧必然是左子树，右侧必然是右子树。

最后再考虑一下终止条件，就是这样一直划分到数组为空。


这道题和[105题](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)的递归法解题思路几乎一样，没有做过的小伙伴也可以再拿105题来练手。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[in]) -> TreeNode:
        if not len(nums):
            return 
        mid = len(nums) // 2
        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[: mid])
        root.right = self.sortedArrayToBST(nums[mid + 1: ])
        
        return root 
        
```