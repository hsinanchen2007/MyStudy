![image.png](https://pic.leetcode-cn.com/ac6e362e80c730a06b9b6087729a0f93ef92b81c487eda61ffdd09b3b19e1757-image.png)

按层递归遍历到目标层的前一层按规则直接改树，注意第一层是边界，需要单独输出。

```python []
class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            r = TreeNode(v)
            r.left = root
            return r
        def f(r, i):
            if r:
                if i < d-1:
                    f(r.left, i + 1)
                    f(r.right, i + 1)
                else:
                    t = TreeNode(v)
                    t.left = r.left
                    r.left = t
                    t = TreeNode(v) 
                    t.right = r.right
                    r.right = t
        f(root, 1)
        return root
```
