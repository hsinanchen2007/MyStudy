一 算法思路
层次遍历二叉树，如果树为空，直接返回0。否则将树和深度值1入队列，逐一弹出队列中节点，若某节点左右子树均为空，此节点即为最小深度的叶子节点，返回其深度即可。若其存在子树，则将其存在的子树和子树深度入队列。
二 算法实现
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        de = collections.deque()
        de.append((root, 1))
        while de:
            p, dep = de.popleft()
            if not p.left and not p.right:
                return dep
            if p.left:
                de.append((p.left, dep+1))
            if p.right:
                de.append((p.right, dep+1))
```
三 复杂度分析
1 时间复杂度
平均和最坏O(N)，N为树中节点数。
2 空间复杂度
最小深度前树的宽度

补充：利用层次遍历可解决一系列相关问题，有兴趣的朋友可参阅[deque团灭层次遍历系列](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/solution/dequeshi-xian-ceng-ci-bian-li-by-jia-zhi-tong-1/)