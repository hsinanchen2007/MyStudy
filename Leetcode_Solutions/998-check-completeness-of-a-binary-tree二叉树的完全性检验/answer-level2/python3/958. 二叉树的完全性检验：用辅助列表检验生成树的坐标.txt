![image.png](https://pic.leetcode-cn.com/6c7d6128567f9e81b0da285189db6957e54b076ccef84cc256441fb318109ca4-image.png)

列表尾部加入值不影响列表的for循环，所以可以直接加，坐标如果是完全二叉树的话，尾坐标和对应长度一定是完美的，否则就不是完全二叉树。

```python []
class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        q = [[root, 1]]
        for r, i in q:
            if r:
                q += [[r.left, i * 2]]
                q += [[r.right, i * 2 + 1]]
        return q[-1][1] == len(q)
```

两种写法差不多，第二种生成的队列q比第一种短一半，但在提交过程中并没有体现出速度优势。

```python []
class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        q = [[root, 1]]
        for r, i in q:
            if r.left:
                q += [[r.left, i * 2]]
            if r.right:
                q += [[r.right, i * 2 + 1]]
        return q[-1][1] == len(q)
```
