思路是如果左子树和左子树都是BST,并且当前node的值大于左子树最大值和右子树最小值的时候,
当前node可以和左右子树构成BST, 记录当前路径和,并尝试更新全局变量(最大路径和)

函数返回值定义为4个,`leftmax`表示左子树的最大值,`rightmin`同理
```
[isBST(bool), cur_sum(int), leftmax, rightmin]
```
然后用后序遍历, 对于空节点,状态为`[True, 0, -inf, inf]`
后续的操作就是开始说的, 如果左右子树和当前节点的值符合BST,返回True,更新路径和和leftmax, rightmin
如果不满足的话, 直接返回 `[False, 0, -inf, inf]`,继续搜索就可以了


```python
class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        inf = 10**9
        res = 0
        def helper(node):
            nonlocal res
            # isBST, cur_sum, leftmax, rightmin
            if not node:
                return True, 0, -inf, inf
            lbst, l_sum, llmax, lrmin = helper(node.left)
            rbst, r_sum, rrmax, rrmin = helper(node.right)
            if lbst and rbst and llmax < node.val < rrmin:
                cur_sum = l_sum + r_sum + node.val
                res = max(res, cur_sum)
                return True, cur_sum, node.val, node.val
            else:
                return False, 0, -inf, inf
        helper(root)
        return res
```