### 解题思路
1. 由二叉树的相关知识可知：
     **·** 二叉树的三种深度优先遍历中的任何一种（前序/中序/后序）都无法唯一确定一个二叉树；
     **·** 只有（中序+前序）或（中序+后序）才能唯一确定一个二叉树。
2. 所以本题只给了一个有序数组，相当于二叉搜索树的中序遍历，没法确定一个唯一的结果，虽然添加了附加条件（要求左右子树的高度差不超过1），仍有多种情况。
3. 故根据此附加条件，最简便的方法就是取数组的中间值为根节点，将数组分成近乎相等的两个部分（若数组的个数是奇数个，则左右部分刚好相等；若数组个数是偶数个，左子树和右子树相差为1），然后递归用同样的方法去重建左子树和右子树，最后返回根节点即可。


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        mid = len(nums) // 2
        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid+1:])
        return root
```