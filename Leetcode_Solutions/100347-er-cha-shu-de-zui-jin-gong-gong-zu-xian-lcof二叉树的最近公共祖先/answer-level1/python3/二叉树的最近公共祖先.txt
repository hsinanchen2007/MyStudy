### 解题思路
这道题是[面试题68 - I. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-10/)进阶，其实一个是自上向下（前序遍历），一个是自下向上（后序遍历）
后序遍历（左右`根`）：我们只需要去考虑对当前的节点进行什么操作？

我们先想想对于一个节点，啥时候我们才将它认为是p和q的公共祖先呢？
1、如果该节点是p和q中的一个，并且另一个在这个节点的左右子树中，那么该节点就是最近的公共祖先，如下图
![image.png](https://pic.leetcode-cn.com/7c5a2b83f5ab2206b93f265a9ed0fa51eb30f2011df194999aad767c5a244542-image.png)

2、如果该节点的左右子树中各自包含p和q，那么该节点就是最近的公共祖先，如下如
![image.png](https://pic.leetcode-cn.com/1f4f635e7c087dd581421fde6ba92fbc6739c6c7631c7c12b92f2e1b2130771c-image.png)

我们自下而上对每个节点继续标记，
·如果`根`节点的左右节点包含p和q，返回`根`
·如果`根`节点是p和q的一个，且另一个在左子树和右子树中，返回`根`，如果另一个不在左右子树中，返回False
·如果左右子树都是False，返回False
·如果左右子树一个是False，返回True
![image.png](https://pic.leetcode-cn.com/b910358d534d396d3115034e040d81f22121aa74d7cee57ed8d9f5595e3047a5-image.png)


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

        self.ans = None
        def help(root, p, q):
            if root is None:
                return False

            left = help(root.left, p, q)
            right = help(root.right, p, q)
            
            if root.val == p.val or root.val == q.val:
                if left or right:
                    self.ans = root
                else:
                    return True
            if left and right:
                self.ans = root
            
            elif left or right:
                return True
            elif not left and not right:
                return False
        help(root,p, q)
        return self.ans
```