**思路：**

题目要返回最深叶结点的最近公共祖先。由于最深的叶结点可能有多个（如果只有一个最深的叶结点，那么它的最近公共祖先就是它自己），我们观察它们最近公共祖先的性质。首先，我们可以看出最近公共祖先的两个子树是等高的，如果不等高，那么高度较小的那个子树叶结点必然不是最深。所以我们可以设计这样的深度优先搜索算法，每一层返回值有两部分组成：一部分是以该结点为根的子树中，最深叶结点的公共祖先，另一部分是该层的高度（也即该结点到其最深叶结点的深度）。然后我们可以递归比较：

1. 如果一个结点的左子树和右子树高度相等，那么其左子树的最深结点和右子树的最深结点，都是以这个结点为根的最深叶结点，那么我们就返回这个结点，和这个结点的高度（左子树高度或右子树高度加 $1$）；
2. 如果一个结点的左子树高度大于右子树，那么以这个结点为根的树，其最深叶结点一定在左子树中，那么我们就返回其左子树中最深结点的最近公共祖先，和当前结点的高度（左子树高度加 $1$）；
3. 如果一个结点的右子树高度大于左子树，那么我们处理情况和情况2相反，返回右子树中最深结点的最近公共祖先，和当前结点的高度（右子树高度加 $1$）。


**代码：**
```python [-Python]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if not root:
                return None, 0
            lr, ld = dfs(root.left)
            rr, rd = dfs(root.right)
            if ld > rd:
                return lr, ld + 1
            elif ld < rd:
                return rr, rd + 1
            else:
                return root, ld + 1
        ans, h = dfs(root)
        return ans
```