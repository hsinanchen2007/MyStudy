![image.png](https://pic.leetcode-cn.com/431060e1a9959552b1f1bb40f9a4ca80931c5dd5fcb158612cd240dd4ad52952-image.png)

不用转字符串，也不用十进制二进制互转，也不用位运算，就直接当普通数字算。

`h`代表当前点深度，`s(h)`代表当前点二进制数（实际上是十进制表示的）,`s(h-1)`当前节点父节点的二进制数值，于是有递推关系，`s(h) = s(h - 1) * 2 + r.val`。

每次递归一层就多迭代一次公式，递归到底时就累加到全局总和里面，也可直接递归写返回值。

时间复杂度$O(N)$，非栈额外空间复杂度$O(1)$。

```python []
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        ans = 0
        def f(r, s):
            if r:
                s = s * 2 + r.val
                if not r.left and not r.right:
                    nonlocal ans
                    ans += s
                else:
                    f(r.left, s)
                    f(r.right, s)
        f(root, 0)
        return ans
```
```python []
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def f(r, s):
            if r:
                s = s * 2 + r.val
                if not r.left and not r.right:
                    return s
                return f(r.left, s) + f(r.right, s)
            return 0
        return f(root, 0)
```
