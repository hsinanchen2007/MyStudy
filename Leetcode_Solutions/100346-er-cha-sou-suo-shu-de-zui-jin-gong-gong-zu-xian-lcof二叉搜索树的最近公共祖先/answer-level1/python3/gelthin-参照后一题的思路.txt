### 解题思路
构造一个递归函数 helper 函数，检查是否在以 root 为根的树中出现 p, q 中的任何一个节点，如果有，则返回 True, 没有就返回 False.

然后在主函数中调用 helper 函数，判断是否
+ 当前 root 是 p or q, 则返回 root
+ 当前 root.left 中有p 或 q, root.right 中也有 p 或 q, 则返回 root
+ 当前 root.left 没有p 或者q, 则说明在 root.right 中，递归去检查 root.right
+ 当前 root.right 没有p 或者q, 则说明在 root.left 中，递归去检查 root.left

##### 但不知道这样是不是复杂度过高，毕竟 helper 函数重复调用了很多次，且重复处理了很多子问题。
确实复杂度过高，其实我的后一题题解直接用 self.lowestCommonFather() 这一个函数来作为 helper() 函数，这个非常巧妙。
self.lowestCommonAncestor() 函数起的作用是，
+ 如果 p,q 有一个在root 树里， 则返回对应节点 p 或者 q, 
+ 如果 p,q 都在 root 树里，则返回 p,q 的最近公共祖先
+ 如果 p,q 都不在 root 树里，则返回 None

```python3
 def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
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



### 不知道这一题每个值唯一有什么用，是否能够用来加速。


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        def helper(root, p, q): # check p, q 是否有一个在 root 树中
            if root == None:
                return False
            if root == p or root == q:
                return True
            else: 
                return helper(root.left, p, q) or helper(root.right, p, q)

        if root == None:
            return None
        if root == p or root == q:
            return root
        left = helper(root.left, p, q)
        right = helper(root.right, p, q)
        if left and right:
            return root
        elif left:
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return self.lowestCommonAncestor(root.right, p, q)
```