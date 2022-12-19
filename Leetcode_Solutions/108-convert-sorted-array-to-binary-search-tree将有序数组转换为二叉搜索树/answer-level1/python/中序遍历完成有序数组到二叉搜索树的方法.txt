### 解题思路
1.判断一下left and right
2.确认根节点（中间位置的左边）
3.通过递归root.left左子树 root.right右子树
4.返回root

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def inorder_BST(left,right):
            if left > right:
                return None
            p = (left + right) // 2
            root = TreeNode(nums[p])
            root.left = inorder_BST(left,p-1)
            root.right = inorder_BST(p+1,right)
            return root

        return inorder_BST(0,len(nums)-1) 
       




```