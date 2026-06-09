
## 思路
这个是我一直在用的回溯模板，想要更多模板可以关注我的公众号，公众号在题解下方。


值得注意的是，我们不能这么写：

如果这样写的话，那么对于题目给的测试用例：

```
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1


```

我们会返回：

```
[
   [5,4,11,2],
   [5,4,11,2],
   [5,8,4,5],
   [5,8,4,5]
]
```

可以看出每一个都形成了两份，原因在于对于每一个子节点，他们的左右子节点分别是空。我们计算了两次，导致push了一次。 

```python
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        def backtrack(nodes, temp, cur, remain):
            if not cur:
                if remain == 0:
                    res.append(temp.copy())
                return
            temp.append(cur.val)
            backtrack(nodes, temp, cur.left, remain - cur.val)
            backtrack(nodes, temp, cur.right, remain - cur.val)
            temp.pop(-1)
        res = []
        backtrack(res, [], root, target)
        return res
```

一种简单的方式就是修改递归终止条件，代码见代码区。


## 代码

```python
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        def backtrack(nodes, temp, cur, remain):
            if not cur: return
            if cur and not cur.left and not cur.right:
                if remain == cur.val:
                    res.append((temp + [cur.val]).copy())
                return
            temp.append(cur.val)
            backtrack(nodes, temp, cur.left, remain - cur.val)
            backtrack(nodes, temp, cur.right, remain - cur.val)
            temp.pop(-1)
        res = []
        backtrack(res, [], root, target)
        return res
```



**复杂度分析**
- 时间复杂度：$O(2^N)$
- 空间复杂度：$O(2^N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)