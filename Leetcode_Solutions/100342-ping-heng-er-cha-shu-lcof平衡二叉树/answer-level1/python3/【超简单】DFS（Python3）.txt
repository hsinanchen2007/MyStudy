## 思路

首先我们需要一个计算树深度的函数，这个有LeetCode原题，其实和层次遍历类似，只不过我们不需要返回层次遍历结果，而是返回树深。

- 如果左右子树深度差绝对值大于1，那么一定不平衡
- 否则我们继续不断递归左右子树


这种方法虽然复杂度很高，但是对付easy题足够了。

## 代码


```python
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def maxDepth(root: TreeNode) -> int:
            def dfs(node, level):
                if not node: return level
                return max(dfs(node.left, level + 1), dfs(node.right, level + 1))
            return dfs(root, 0)
        if not root: return True
        if not abs(maxDepth(root.left) - maxDepth(root.right)) < 2: return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
    
```


欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
