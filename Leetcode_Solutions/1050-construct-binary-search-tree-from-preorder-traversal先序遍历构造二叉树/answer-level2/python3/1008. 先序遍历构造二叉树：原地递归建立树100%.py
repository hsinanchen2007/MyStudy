### 方法一：

取序列首元素作为树根，序列里小于等于首元素的值递归进左子树，大于的递归进右子树，最后输出，港实话代码结构有点像快排。

![image.png](https://pic.leetcode-cn.com/fef6d6ceb35f53bfa56b991dd60e88dc63d13083a5c5e33730f4311e371db584-image.png)

```python []
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if preorder:
            p, root = [[], []], TreeNode(preorder.pop(0))
            [p[val > root.val].append(val) for val in preorder]
            root.left = self.bstFromPreorder(p[0])
            root.right = self.bstFromPreorder(p[1])
            return root
```
```python []
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if preorder:
            root = TreeNode(preorder.pop(0))
            l, r = [], []
            for i in preorder:
                if i <= root.val:
                    l += [i]
                else:
                    r += [i]
            root.left = self.bstFromPreorder(l)
            root.right = self.bstFromPreorder(r)
            return root
```
```python []
from collections import deque as d
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        def f(q):
            if q:
                p, root = [d(), d()], TreeNode(q.popleft())
                [p[val > root.val].append(val) for val in q]
                root.left, root.right = f(p[0]), f(p[1])
                return root
        return f(d(preorder))
```

### 方法二：

仍然是取首元素作为根节点，然后找到小于根节点的分界线对数组进行二分递归即可，减少了`pop(0)`的操作，程序更快了，如果还有优化的点的话，就是写成闭包函数，把递归的参数由传输组变成传坐标。

![image.png](https://pic.leetcode-cn.com/e121a5eb88a017b83fc83a91897e8fd55f4e1d64e5132ae873d0208ef1b5edba-image.png)

```python []
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if preorder:
            root = TreeNode(preorder[0])
            devide = next((i for i, val in enumerate(preorder) if val > root.val), len(preorder))
            root.left = self.bstFromPreorder(preorder[1: devide])
            root.right = self.bstFromPreorder(preorder[devide: ])
            return root
```
```python []
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        def f(l, r):
            if l < r:
                root = TreeNode(preorder[l])
                devide = next((i for i in range(l + 1, r) if preorder[i] > root.val), r)
                root.left = f(l + 1, devide)
                root.right = f(devide, r)
                return root
        return f(0, len(preorder))
```
```python []
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        s, p = [], preorder and [(0, len(preorder), -1)]
        while p:
            l, r, f = p.pop()
            if l < r:
                s.append(TreeNode(preorder[l]))
                if f >= 0:
                    if s[-1].val < s[f].val:
                        s[f].left = s[-1]
                    else:
                        s[f].right = s[-1]
                devide = next((i for i in range(l + 1, r) if preorder[i] > s[-1].val), r)
                p.append((devide, r, l))
                p.append((l + 1, devide, l))
        return s and s[0]
```
