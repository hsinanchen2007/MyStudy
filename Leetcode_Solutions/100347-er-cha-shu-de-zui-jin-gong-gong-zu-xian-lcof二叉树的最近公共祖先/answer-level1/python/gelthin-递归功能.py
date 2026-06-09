### 解题思路
同主站习题 [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)
接连错 4 回，并且下面这个代码只适用于满足性质： p、q 为不同节点且均存在于给定的二叉树中。
如果没有这一性质，比如说，只有 p 没有q, 那么这个代码会犯错，会返回 p.

这一代码来自于题解[简单易懂，详解如下](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/jian-dan-yi-dong-xiang-jie-ru-xia-by-yuanninesuns/)
在 leetcode 主站评论区也看到[此解法](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetcod/213511)

但这个解法有点难以理解，这个题解这里的 left 和 right 是子问题的解，而不是当前 root.left 和root.right。

### 所谓的递归，要弄清楚递归的含义，这个函数到底起到了什么功能，这个要想清楚

+ 1. 判断 p,q 在不在 root 所在的树，如果在，返回 root
+ 2. 还是 判断 p,q 在不在 root 所在的树，如果在，返回 p,q 的第一个公共父节点


我自己最初的题解写的一塌糊涂，最后一次还报超时，弄了一个辅助函数，递归过长，每次在根节点的位置判断，都需要搜索整个左右子树，要递归到最深处去判断。 不像二叉搜索树搜索，只需要在根节点做一次比较。


在好的题解 self.lowestCommonAncestor() 函数起的作用是，
+ 如果 p,q 有一个在root 树里， 则返回对应节点 p 或者 q, 
+ 如果 p,q 都在 root 树里，则返回 p,q 的最近公共祖先
+ 如果 p,q 都不在 root 树里，则返回 None

而这个题解递归次数理论上递归次数应该也差不多，不知为何，这个题解能过。
这个题解这里的 left 和 right 是子问题的解，而不是当前 root.left 和root.right, 所以实际上
其只要每个节点遍历一次。




而我最初的题解，在每个节点处，都需要把其子树遍历一遍，重复做无用功，
那么实际上叶子节点就遍历了 O(n) 次, 复杂度是 O(n^2)
我这里是定义了一个 help 函数，然后不断调用这个 help 函数。在子树中找到了，再去遍历子树，过于复杂。

###### 超时的代码 
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        def isnode(root, p):
            if root == p:  # 自己是自己的祖先
                return True
            r1 = False
            if root.left:
                r1 = isnode(root.left, p)
            r2 = False
            if root.right:
                r2 = isnode(root.right, p)
            return r1 or r2
    
        if root == None:
            return None
        # 所有节点的值都是唯一的。
        # p、q 为不同节点且均存在于给定的二叉树中。
        
        ## 代码打了一堆补丁，但没有从逻辑上修复这个问题，丑陋的代码
        # if root == p:  
        #     if root.left == q or root.right == q:
        #         return root
        # if root == q:
        #     if root.left == p or root.right == p:  
        #         # return True  BUG
        #         return root
        
        if root == p or root == q:
            return root

        A1, A2 = False, False
        if root.left:
            A1 = isnode(root.left, p)
            A2 = isnode(root.left, q)
        
        B1, B2 = False, False
        if root.right:
            B1 = isnode(root.right, p)
            B2 = isnode(root.right, q)
        if (A1 and B2) or (A2 and B1):
            return root
        elif (A1 and A2):
            if (root.left == p) or (root.left==q):  # 就是这里要处理
                return root.left
            else:
                return self.lowestCommonAncestor(root.left, p, q)
        elif (B1 and B2):
            if root.right == p or root.right == q:   # p,q 的共同祖先是 p 或者 q
                return root.right
            else:
                return self.lowestCommonAncestor(root.right, p, q)
```


 

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        # if root == None or root==p or root==q:
        #     return root
        # A = self.lowestCommonAncestor(root.left, p, q)
        # B = self.lowestCommonAncestor(root.right, p, q)
        # if A:   #BUG 这里因为只要找到一个就返回了，当A 和 B 都是 True 的时候，就会出错。
        #     return A 
        # if B:
        #     return B 
        # return root
        ### 可改为：#####
        # if not A:
        #     return B
        # if not B:
        #     return A 
        # return root



        # 利用了这一个性质： p、q 为不同节点且均存在于给定的二叉树中。
        # 如果只有一个存在，则这个方法不对

        if not root or root == p or root == q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)  # 检查 left 中是否包含 p 或者 q
        right = self.lowestCommonAncestor(root.right, p, q)
        
        if left and right:
            return root
        if left and not right:
            return left
        if right and not left:
            return right
        if not right and not left:
            return None

```