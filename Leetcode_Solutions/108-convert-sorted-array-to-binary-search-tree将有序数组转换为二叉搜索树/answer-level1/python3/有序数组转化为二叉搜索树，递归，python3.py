### 解题思路
选取数组中间值作为根节点
中间值左边的数组形成平衡二叉树作为跟节点的左子树
中间值右边的数组形成平衡二叉树作为根节点的右子树
递归调用本函数
终止条件：数组为空

![数组2平衡二叉树.png](https://pic.leetcode-cn.com/c41cb55e55c9fb3c1559edef9b1db1f7058dd12a556689a0dfd755cb96fa23ed-%E6%95%B0%E7%BB%842%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91.png)


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
            return
        mid = len(nums) // 2
        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid+1:])
        return root
```