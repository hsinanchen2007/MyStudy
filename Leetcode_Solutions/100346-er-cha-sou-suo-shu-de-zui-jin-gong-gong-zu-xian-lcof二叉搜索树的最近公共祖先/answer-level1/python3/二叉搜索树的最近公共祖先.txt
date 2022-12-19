### 解题思路
这道题利用一下二叉搜索树特征很好做（其实就是前序遍历【`根左右`或者`根右左`】）
我们知道对于这个`根`我们需要干什么？
1、如果`根`的值在p和q之间，我们直接得出最近公共祖先就是这个`根`
2、如果`根`的值大于p和q，那么我们就得在`根`的左子树上去找最近公共祖先
3、如果`根`的值小于p和q，那么我们就得在`根`的右子树上去找最近公共祖先

![image.png](https://pic.leetcode-cn.com/58880f9728272a347d40bcf51dfe49cf9706a46e2a8db378076f317a9e7d400d-image.png)


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
        if p.val > q.val:
            p, q = q, p
        self.ans = None
        def help(root, p, q):
            if root is None:
                return 
            if root.val >= p.val and root.val <= q.val:
                self.ans = root
            if root.val < p.val and root.val < q.val:
                help(root.right, p, q)
            if root.val > p.val and root.val > q.val:
                help(root.left, p, q)
        help(root, p, q)
        return self.ans
```