### 解题思路
两种方法：
注意题中要求是返回以该节点为根的子树，不是返还节点的值，而是返回节点自身
1.递归：
时间复杂度O(H)，H为树的高度，N个节点，一般情况下H为logN，最坏情况为N
空间复杂度O(H)
2.遍历
时间复杂度O(H)，H为树的高度，N个节点，一般情况下H为logN，最坏情况为N
空间复杂度O(1)

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def searchBST(self, root, val):#递归
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if not root: 
            return None
        elif root.val == val: #如果等于目标值，返回该结点
            return root
        elif root.val >val: #大于目标值，搜索左子树
            return self.searchBST(root.left,val)
        else:    #小于目标值，搜索右子树
            return self.searchBST(root.right,val)


    def searchBST(self, root, val):#遍历
        while root:
            if root.val== val:
                return root
            elif root.val > val:
                root = root.left
            else:
                root = root.right
        return None


    






```