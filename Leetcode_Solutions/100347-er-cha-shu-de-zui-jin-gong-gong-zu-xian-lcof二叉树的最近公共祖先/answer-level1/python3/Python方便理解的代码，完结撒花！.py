### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
    # 首先明确，这里由于需要知道p、q节点和父节点的关系，因此需要返回一定的变量
    # 需要处理p、q共同父节点为公共祖先，p或q为公共祖先三种情况
    # recur函数返回当前节点对p、q的匹配情况，特别包含了三种情况的判断
    def lowestCommonAncestor(self, root, p, q):
        if not root: return
        self.re = None
        def recur(r):
            # 注意由于函数有返回值，因此都得设置None
            if not r: return None, None
            if self.re: return None, None
            # 这里左右子节点的遍历顺序无关，但必须得在当前节点之前遍历，即后序遍历
            l_p, l_q = recur(r.left)
            # 情况一:左子节点为公共祖先且为p、q之一
            if l_p and l_q:
                self.re = r.left
                return None, None
            r_p, r_q = recur(r.right)
            # 情况二:右子节点为公共祖先且为p、q之一
            if r_p and r_q:
                self.re = r.right
                return None, None
            # 情况三:当前父节点为公共祖先
            if (l_p or r_p) and (l_q or r_q):
                self.re = r
                return None, None
            # 当前节点没有完全匹配p、q的返回值
            return r.val == p.val or l_p or r_p, r.val == q.val or l_q or r_q
        # 根节点的匹配也要考虑！
        m_p, m_q = recur(root)
        if m_p and m_q: self.re = root
        return self.re
```