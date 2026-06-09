## 思路

树的题目我们都可以用DFS来做，简单省事。 和常规的使用DFS来进行层次遍历代码差不多，思路也差不多一样的。

## 代码

```
class Solution:
    def listOfDepth(self, root: TreeNode) -> List[ListNode]:
        ans = []
        def dfs(node, level):
            if not node: return None
            if len(ans) == level:
                ans.append(ListNode(node.val))
            else:
                head = ListNode(node.val)
                head.next = ans[level]
                ans[level] = head
            dfs(node.right, level + 1)
            dfs(node.left, level + 1)
        dfs(root, 0)
        return ans

```

**复杂度分析**
- 时间复杂度：$O(N)$，其中N为节点数。
- 空间复杂度：$O(N)$，其中N为节点数。

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
