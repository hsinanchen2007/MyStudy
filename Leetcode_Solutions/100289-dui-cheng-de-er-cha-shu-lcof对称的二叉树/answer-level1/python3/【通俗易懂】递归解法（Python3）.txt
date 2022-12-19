
我们只需要拿`左子树的右节点`和`右子树的左节点`进行递归比较即可。用代码来说就是:`helper(l.right, r.left) and helper(l.left, r.right)`。
而base case就比较简单了，如果两个节点的根节点不同，那么肯定不对，返回False，如果两个都是None了，返回True。


```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def helper(l, r):
            if (l and not r) or (r and not l):
                return False
            if not l and not r:
                return True
            if l.val != r.val:
                return False
            return helper(l.right, r.left) and helper(l.left, r.right)
        if not root: return True
        return helper(root.left, root.right)
```

**复杂度分析**
- 时间复杂度：$O(N)$，其中N为树的节点总数。
- 空间复杂度：$O(N)$，其中N为树的节点总数。

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)