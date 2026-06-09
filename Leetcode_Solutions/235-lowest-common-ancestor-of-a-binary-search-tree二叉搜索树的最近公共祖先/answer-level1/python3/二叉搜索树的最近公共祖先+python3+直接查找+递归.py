### 直接查找
基于二叉搜索树的特性，直接查找最近的公共祖先。最近公共祖先应该是第一个介于p,q之间的节点（这题p,q大小关系不定），直接搜索就可以了。代码如下：
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val >q.val:
            p,q =q,p
        while True:
            if root.val>q.val:
                root = root.left
            elif root.val < p.val:
                root = root.right
            else:
                return root    
```
#### 复杂度分析
__时间复杂度：__ O(n),每个元素访问一遍

__空间复杂度：__ O(l),没有用到额外空间

### 递归
递归也是基于搜索树的特点，如果当前值小于于p.val，递归左子树，若干大于q.val递归右子树。返回第一个在[p,q]之间的值（闭区间）。代码如下：
```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val >q.val:
            p,q =q,p
        def find(root,p,q):
            if not root:
                pass
            elif root.val > q.val:
                return find(root.left,p,q)
            elif root.val < p.val:
                return find(root.right,p,q)
            else:
                return root
        return find(root,p,q)
```
#### 复杂度分析
__时间复杂度：__  O(n)，每个值至多访问一遍

__空间复杂度：__  O(n) ,没有使用额外的空间