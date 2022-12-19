### 解题思路
1. 比之简单的题目
    - [BST 二叉树搜索数 的 最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/bst-er-cha-shu-sou-suo-shu-de-zui-jin-gong-gong-zu/)

2. 题解（前提条件很重要）：
    - 公共祖先：1）有一个是父节点本身，返回父节点； 
    - 2）lf 左侧搜索P / Q，rf 右侧搜索P/Q，若lf 和 rf 均找到，return 父节点 **（后序遍历 pastOrder）**；
    - 3）**若 lf 没找到，返回 rf； 若rf 没找到，返回lf ,这是关键**




### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

'''
class Solution:
    def __init__(self):
        self.lf = False
        self.rf = False 
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None:
            return None 
        
        if root.val == p.val or root.val == q.val:
            return root
        
        self.find_pq(root, p, q)

    def find_pq(self, root, p, q):
        if root is None:
            return False 
        if root.val == p.val or root.val == q.val:
            return True 
        
        lf = find_pq(root.left, p, q)
        rf = find_pq(root.left, p, q)
        
        if lf and rf:
            return root 
'''
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None or root == p or root == q:
            return root 
        
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        if left is not None and right is not None:
            return root 
        
        return right if left is None else left 


        


```