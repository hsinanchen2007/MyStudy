### 解题思路
对比的是左右子树是否可以重叠，所以：
左子树的左孩子 = 右子树的右孩子
左子树的右孩子 = 右子树的左孩子

# 递归的终止条件是
  1. 两个节点都为空
  2. 或者两个节点中有一个为空
  3. 或者两个节点的值不相等

# 原作者：user7439t #

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def dfs(left,right): # 因为需要对比的是左右子树，故而递归函数需要两个结点，所以自定义带两个参数的递归函数
	    	if not (left or right):  # 两个结点都为空时，说明已经都遍历完了，对称
		    	return True
	    	if not (left and right): # 两个结点中有一个为空，非对称
		    	return False
	    	if left.val!=right.val:  # 两个结点对值不想等，非对称
		    	return False
	    return dfs(left.left,right.right) and dfs(left.right,right.left)

        if not root:
			return True
        else:
		    return dfs(root.left,root.right) # 用递归函数，比较左节点，右节点



```