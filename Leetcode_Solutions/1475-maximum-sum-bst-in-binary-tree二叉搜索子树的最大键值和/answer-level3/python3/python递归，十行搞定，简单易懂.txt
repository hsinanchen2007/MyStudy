解题思路：DFS，自底向上递归。通过辅助函数，把以当前节点为根节点的二叉搜索树的键值和,上界,下界传出来；值得注意的是，当局部子树不满足二叉搜索树条件时，将上下界设置为恒不成立，一直回传。

    class Solution:
        def maxSumBST(self, root: TreeNode) -> int:
            self.max_value = 0
            self.helper(root)
            return self.max_value
            
        def helper(self, root):
            # 返回三个变量
            # 分别为【以当前节点为根节点的二叉搜索树的键值和】,【上界】,【下界】
            if not root:
                return 0, 5e4, -5e4 
            value1, min_value1, max_value1 = self.helper(root.left)
            value2, min_value2, max_value2 = self.helper(root.right)         
            if max_value1 < root.val and min_value2 > root.val: 
                # 满足二叉搜索树条件
                self.max_value = max(self.max_value, value1 + value2 + root.val)
                return value1 + value2 + root.val, min(min_value1, root.val), max(max_value2, root.val)
            # 说明该节点无法构成二叉搜索树，返回恒不成立的条件，一直返回到顶
            return root.val, -5e4, 5e4  
            