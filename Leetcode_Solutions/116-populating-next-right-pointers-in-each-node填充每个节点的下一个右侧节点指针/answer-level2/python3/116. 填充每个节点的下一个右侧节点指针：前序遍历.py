![image.png](https://pic.leetcode-cn.com/4a6486fbfbb072601e060c05db9ee8e6dfc88481fd80d39070db78b298cb4a77-image.png)

扩数据前最好是64ms, 93.35%。

**方法一：** 字典存层法，逻辑比较简单，就是按层存最右，但空间复杂度并不符合题意。

```python []
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        d = collections.defaultdict(lambda: None)
        def f(r, i):
            if r:
                r.next, d[i] = d[i], r
                f(r.right, i + 1)
                f(r.left, i + 1)
        f(root, 0)
        return root
```

**方法二：** 直接原地递归的方法，按层递归传递指针，符合题意。

```python [1]
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root:
            l, r = root.left, root.right
            while l:
                l.next, l, r = r, l.right, r.left
            self.connect(root.left)
            self.connect(root.right)
            return root
```
