## [1339. 分裂二叉树的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-splitted-binary-tree)
### 题意：
在一棵二叉树里,每个节点有一个数值，随意的删除一条边，使分裂的二叉树的乘积尽可能大。

### 思路：
树型搜索的题目，一遍dfs(深度优先搜索)遍历二叉树，保存以每个节点为根子树的和。 然后枚举删除整个树和这个子树之间的边进行判断。

### 代码：
```python
class Solution:
    def dfs(self, root):
        self.num[root]  = root.val
        if root.left != None : self.num[root] += self.dfs(root.left)
        if root.right != None: self.num[root] += self.dfs(root.right)
        return self.num[root]

    def maxProduct(self, root) :
        self.num = {}
        self.dfs(root)
        ans, all = 0, self.num[root]
        for node in self.num:
            ans = max(ans , (all - self.num[node]) *self.num[node])
        return int(ans % (1e9+7))
```