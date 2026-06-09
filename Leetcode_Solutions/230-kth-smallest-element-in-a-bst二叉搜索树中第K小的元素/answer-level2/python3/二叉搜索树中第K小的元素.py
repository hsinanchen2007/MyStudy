一 算法思路
由于二叉搜索树的中序遍历序列为递增序列，因此可中序遍历二叉搜索树，返回访问到的第K个元素，即为二叉搜索树中第k小的元素。
二 算法实现
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        st = []
        p = root
        s = 0
        while p is not None or st:
            while p is not None:
                st.append(p)
                p = p.left
            p = st.pop()
            s += 1
            if s == k:
                return p.val
            p = p.right
```
三 复杂度分析
时间复杂度：O(N)，N为树中节点个数。
空间复杂度：O(log(N))。
补充：二叉搜索树的中序遍历序列为递增序列，灵活利用这一性质可解决一系列二叉搜索树问题。有兴趣了解利用该性质解决相关问题的朋友，请参阅[中序遍历团灭系列二叉搜索树问题](https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/solution/zhong-xu-bian-li-tuan-mie-xi-lie-er-cha-sou-suo-sh/)*（刷题不是目的，学习的秘诀在于举一反三，触类旁通，灵活运用。）*