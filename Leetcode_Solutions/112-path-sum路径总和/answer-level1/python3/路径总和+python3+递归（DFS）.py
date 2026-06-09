### 递归
计算每一条路径的累计和，当前仅当有一个叶子节点满足条件时返回True。代码如下：
```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:                                           #当前节点为空，返回Fasle
            return False
        if not root.left and not root.right and root.val==sum: #当前节点符合条件，返回True
            return True
        if root.left:
            root.left.val = root.val+root.left.val             #左节点值等于累计和
        if root.right:
            root.right.val = root.val+root.right.val           #右节点值等于累计和
        return self.hasPathSum(root.left,sum) or self.hasPathSum(root.right,sum)
        # 递归左右子节点
```
#### 复杂度分析
__时间复杂度：__ O(n)
__空间复杂度：__ O(n)