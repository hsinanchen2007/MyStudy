
## 思路
简单起见，我直接用dfs实现了层次遍历。 而题目不需要我们区分不同的层，只让我们返回一个flattened的数组即可，

我们仍然按照普通的层次遍历算法，最终我们flatten一下即可。

> 题目只可能包含两层嵌套，因此无须递归flatten


eg: 

```python
        for i in range(1, len(res)):
            res[0] += res[i]
```
## 代码

```python
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if not root: return []
        res = []
        def dfs(node, level):
            if not node:
                return
            if level == len(res):
                res.append([])
            res[level].append(node.val)
            dfs(node.left, level + 1)
            dfs(node.right, level + 1)
        dfs(root, 0)
        # flatten
        for i in range(1, len(res)):
            res[0] += res[i]
        return res[0]
```

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)