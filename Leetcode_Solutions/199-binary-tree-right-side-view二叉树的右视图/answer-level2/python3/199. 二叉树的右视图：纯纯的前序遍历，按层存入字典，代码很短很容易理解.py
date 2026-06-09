![image.png](https://pic.leetcode-cn.com/a2b86ab8e85c62685fa77a7f93ce532fd9493862e7739613125ef2e90b311946-image.png)


前根序遍历,可以保证按层序新增元素，同时也可以保证每层最后一次遍历到的一定是最右边的元素。

输出时，字典默认遍历序等于定义序，所以可以直接输出字典的值。

```python []
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        d = {}
        def f(r, i):
            if r:
                d[i] = r.val
                f(r.left, i + 1)
                f(r.right, i + 1)
        f(root, 0)
        return d.values()
```