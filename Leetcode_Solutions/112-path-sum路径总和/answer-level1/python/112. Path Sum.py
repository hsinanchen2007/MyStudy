1. 开始自己写出来的，但是不够简洁
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.leaf = False

    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root is not None:
            self.find(root, sum)
        
        return self.leaf

    def find(self, root, sum):
        # 这个部分需要考虑到节点负数情况
        # if root.val > sum:
        #     return
        # 均有值
        if root.left and root.right:
            root.left.val += root.val
            root.right.val += root.val

            self.hasPathSum(root.left, sum)
            self.hasPath
Sum(root.right, sum)

        # 只有一个有值
        elif root.left and root.right is None:
            root.left.val += root.val
            self.hasPathSum(root.left, sum)

        elif root.left is None and root.right:
            root.right.val += root.val
            self.hasPathSum(root.right, sum)
        
        # 到了叶子节点判断
        else:
            if root.val == sum:
                self.leaf = True
        

"""
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

Given the below binary tree and sum = 22
"""

"""
root.left = 5 + 4 = 9 继续
root.right = 5 + 8 = 13 继续

      5
     / \
  [9]   [13]
   /   / \
  11  13  4
 /  \      \
7    2      1

root.left.left = 9 + 11 = 20 继续
root.left.right 无值舍弃
      5
     / \
  [9]   [13]
   /   / \
 [20] [26] [17]
 /  \      \
7    2      1

root.right.left = 13 + 13 = 26 超过该值舍弃
root.right.right = 13 + 4 = 17 继续

root.left.left.left = 20 + 7 > 22 超过该值舍弃
root.left.left.right = 20 + 2 == 22
"""
```

2. 看了别人写的
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        if not root:
            return False

        sum -= root.val
        # leaf
        if not root.left and not root.right:
            return sum == 0
        return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)
```
