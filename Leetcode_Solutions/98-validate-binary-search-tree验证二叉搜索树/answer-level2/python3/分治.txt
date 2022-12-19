### 解题思路
此处撰写解题思路
用分治的思想来解题。判断是否是二叉搜索树，就要判断左子树的最大值是不是比根节点的值小;右子树的最小值是不是比根节点的值大。
只有满足条件才是二叉搜索树
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:

        isBST, leftNode, rightNode = self.divideConquer(root)

        return isBST

    def divideConquer(self, root):

        if root is None:

            return True, None, None

        leftIsBST, leftMin, leftMax = self.divideConquer(root.left)
        rightIsBST, rightMin, rightMax = self.divideConquer(root.right)

        if leftMax is not None and leftMax >= root.val:
            
            return False, None, None
        if rightMin is not None and rightMin <= root.val:
            
            return False, None, None
        if not leftIsBST or not rightIsBST:

            return False, None, None

        #is BST
        minValue = leftMin if leftMin is not None else root.val
        maxValue = rightMax if rightMax is not None else root.val

        return True, minValue, maxValue


```