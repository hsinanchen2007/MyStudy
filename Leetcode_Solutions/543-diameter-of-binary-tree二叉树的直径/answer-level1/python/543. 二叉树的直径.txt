### 解题思路
其实二叉树的题目套路挺固定的，都是向左树和右树要信息，一开始想了很复杂，一个一个遍历节点，但是其实只要利用递归就可以了，不需要用for循环，这是利用了系统栈帮忙实现的。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 1
        def depth(node):
            if not node:
                return 0
            L = depth(node.left)
            R = depth(node.right)
            self.ans = max(self.ans,L+R+1)
            return max(L,R)+1
        depth(root)
        return self.ans-1
        # cur1 = root.left
        # cur2 = root.right
        # leftcount = 0
        # rightcount = 0
        # while cur.left!=None or cur.right!=None:
        # while cur1.left!=None:
        #     left_object = Solution()
        #     left_num = left_object.diameterOfBinaryTree(cur1)
        #     leftcount = leftcount + left_num
        #     cur1 = cur1.left
        # while cur2.right!=None:
        #     right_object = Solution()
        #     right_num = right_object.diameterOfBinaryTree(cur2)
        #     rightcount = rightcount + right_num
        #     cur2 = cur2.right
        # return leftcount+rightcount


```