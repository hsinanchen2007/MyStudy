## 思路

类似层次遍历，只不过我们返回深度，而不是层次遍历结果。

## 代码

```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        def dfs(node, level):
            if not node: return level
            return max(dfs(node.left, level + 1), dfs(node.right, level + 1))
        return dfs(root, 0)

```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
