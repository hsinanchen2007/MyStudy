![image.png](https://pic.leetcode-cn.com/129c558a7ccb43605c1a88c9fc1c5efc9893c23e6e49f247f982b1d3abac9277-image.png)

提交人数较少，404ms仅供参考。

用一个字典存下每一层的总和，最后按顺序统计就行，由于前序遍历的缘故，字典的默认遍历序为层次升序。

时间复杂度$O(N+H)$，空间复杂度$O(H)$。

```python []
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        d = collections.defaultdict(int)
        def f(r, i):
            if r:
                d[i] += r.val
                f(r.left, i + 1)
                f(r.right, i + 1)
        f(root, 1)
        ans, ct = 0, 0
        for i in d:
            if d[i] > ct:
                ans = i
                ct = d[i]
        return ans
```


更简短的写法，不过因为求了最大值还要再查找坐标，时间复杂度要加个$O(H)$，所以慢一些，多个几十ms这样吧。

```python [1]
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        d = collections.defaultdict(int)
        def f(r, i):
            if r:
                d[i] += r.val
                f(r.left, i + 1)
                f(r.right, i + 1)
        f(root, 1)
        return [*d.values()].index(max(d.values())) + 1
```
