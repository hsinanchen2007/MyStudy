### 解题思路
判断一个二叉树是否合法：左面子树中最大值<当前节点的值<右边子树中的最小值
我们进行递归判断，为空节点时，返回float("inf"), float("-inf")，这样它的任何父节点都将合法
如果当前节点不满足约束条件，返回float("-inf"), float("inf")，这样它的任何父节点都将不合法


### 代码

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestBSTSubtree(self, root: TreeNode) -> int:
        def helper(root):
            if not root:
                return float("inf"), float("-inf"),0
            l_min,l_max,lv=helper(root.left)
            r_min,r_max,rv=helper(root.right)
            if l_max<root.val<r_min:
                return min(root.val,l_min),max(root.val,r_max),lv+rv+1
            return float("-inf"), float("inf"),max(lv,rv)
        return helper(root)[2]
        


```