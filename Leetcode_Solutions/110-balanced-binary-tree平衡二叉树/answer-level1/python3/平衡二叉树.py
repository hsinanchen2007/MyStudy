### 解题思路
利用求最大深度，来计算局部子树深度差。

# 原作者：jyd

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        return self.depth(root) != -1  # 如果等于-1，则不平衡；返回FALSE，是不平衡树，返回True，是平衡树

    def depth(self, root):  # 返回-1时，说明有某个子树的深度差大于1，不平衡
        if not root: 
            return 0
        left = self.depth(root.left)  # 判断左子树，如果左子树已经深度差大于1，则提前终止
        if left == -1: 
            return -1

        right = self.depth(root.right)  # 判断右子树，如果右子树已经深度差大于1，则提前终止
        if right == -1: 
            return -1
        
        if abs(left - right) < 2:  # 单个局部子树没有深度差大于1时，则整个子树进行判断，返回该子树的最大深度，跟别的大的子树进行对比
            return max(left, right) + 1 
        else:
            return -1

```