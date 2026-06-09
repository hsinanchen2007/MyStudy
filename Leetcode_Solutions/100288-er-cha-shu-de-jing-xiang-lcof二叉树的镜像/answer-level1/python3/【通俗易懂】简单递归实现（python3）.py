
注意这样写是不行的哦：


```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root: return None
        root.left = self.mirrorTree(root.right)
        root.right = self.mirrorTree(root.left)
        return root
```

原因在于root.left 已经被修改了，那么self.mirrorTree(root.left) 就不再是原来的root.left 了。 我们只需要用一个变量保存原引用即可。


```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root: return None
        l = root.left
        root.left = self.mirrorTree(root.right)
        root.right = self.mirrorTree(l)
        return root
```

**复杂度分析**
- 时间复杂度：$O(N)$，其中N为树的节点数
- 空间复杂度：$O(N)$，其中N为树的节点数

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)