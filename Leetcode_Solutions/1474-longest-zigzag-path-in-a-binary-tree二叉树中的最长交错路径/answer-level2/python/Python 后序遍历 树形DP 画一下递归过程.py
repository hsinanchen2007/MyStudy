这个题我也是第一次接触, 感觉思路是这样:
访问顺序`[left, right, root]`, 所以用类似后序遍历的方式
统计左右子树的最大ZigZag路径
放一下递归树:
![递归树.jpeg](https://pic.leetcode-cn.com/521540e674bbfbc044802f8108ba8fbef88136c38c8b4b1a89d550780f916e1d-IMG_962808C8613B-1.jpeg)




```python
class Solution:
    def longestZigZag(self, root: TreeNode) -> int:
        res = 0
        def helper(node):
            nonlocal res
            if not node:
                return -1, -1       
            ll, lr = helper(node.left)
            rl, rr = helper(node.right)
            l = lr + 1
            r = rl + 1
            res = max(res, l, r)
            return l, r
        helper(root)
        return res
```