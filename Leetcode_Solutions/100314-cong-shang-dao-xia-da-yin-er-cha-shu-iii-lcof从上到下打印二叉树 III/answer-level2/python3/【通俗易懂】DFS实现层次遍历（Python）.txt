## 思路

简单起见，我直接用dfs实现了层次遍历。和普通层次遍历唯一不同的是：我们需要分奇偶插入，如果是奇数（索引从0开始）我们往前插入，否则我们往后插入。

即:

```python
    res[level].append(node.val)
```


变成了：

```python
    if level % 2 == 1:
        res[level].insert(0, node.val)
    else:
        res[level].append(node.val)
```
## 代码


```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if not root: return []
        res = []
        def dfs(node, level):
            if not node:
                return
            if level == len(res):
                res.append([])
            if level % 2 == 1:
                res[level].insert(0, node.val)
            else:
                res[level].append(node.val)
            dfs(node.left, level + 1)
            dfs(node.right, level + 1)
        dfs(root, 0)
     
        return res
```
欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)