### 解题思路
先序遍历最后遍历到的比当前节点少两层的值一定是当前节点的祖父节点。

### 代码

```python []
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        d = collections.defaultdict(lambda: 1)
        def f(r, i):
            if r:
                if not d[i - 2] & 1:
                    d['ans'] += r.val
                d[i] = r.val
                f(r.left, i + 1)
                f(r.right, i + 1)
        f(root, 0)
        return d['ans'] - 1
```

![image.png](https://pic.leetcode-cn.com/feb939c5bf4580736811511fd4c1dfeca9ff7410db88bef19a0e11af1b4cc0c0-image.png)
