![image.png](https://pic.leetcode-cn.com/2550c13710c705a0b0c96f8679bb4d3ddde09a6ed68b4acd0f7f32a6fd302b9e-image.png)

把判断放进递归里面，就不用单独再循环一次了，虽然不是最快，但应该也算比较好理解的方法了,就是空间大了点

```python []
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        d = {}
        self.ans = False
        def f(r):
            if r:
                if r.val in d:
                    self.ans = True
                    return
                d[k - r.val] = True
                f(r.left)
                f(r.right)
        f(root)
        return self.ans
```
剪枝后更快了,进入递归的时候加了对ans的判断，感谢@fortunely评论提醒

![image.png](https://pic.leetcode-cn.com/97c34de015ce838ffa10137eabf9a38f46231bc5e5f407457d669f678f3dfaa3-image.png)

```python []
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        d = {}
        self.ans = False
        def f(r):
            if r and not self.ans:
                if r.val in d:
                    self.ans = True
                d[k - r.val] = True
                f(r.left)
                f(r.right)
        f(root)
        return self.ans
```

许久没看这题，改进了一下，不用字典用集合，更快了一些。

![image.png](https://pic.leetcode-cn.com/0e25e5dd6ccadf5f819cfe0d402f3c210d7a16fca902936721b9f03eb03bee86-image.png)


```python []
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        d = set()
        ans = False
        def f(r):
            nonlocal ans
            if r and not ans:
                if r.val in d:
                    ans = True
                    return
                d.add(k - r.val)
                f(r.left)
                f(r.right)
        f(root)
        return ans
```
