![image.png](https://pic.leetcode-cn.com/9f093ba7985835df262ad773d927c831e81810a297808204ed5a1367c4fbc48e-image.png)

遍历一次树，怎么遍历都行，然后只用记录最小的两个变量就可以了，可以用堆。

```python []
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        h = [-float('inf'), -float('inf')]
        def f(r):
            if r:
                -r.val not in h and heapq.heappushpop(h, -r.val)
                f(r.left)
                f(r.right)
        f(root)
        return h[0] == -float('inf') and -1 or -h[0]
```

```python []
#刚开始刷题时候写的，可以AC现在已经看不懂了。（不想看了）
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        min1,min2=float('inf'),float('inf')
        def f(r):
            if r:
                nonlocal min1,min2
                if r.val>min1:
                    if r.val<min2:
                        min2=r.val
                else:
                    if min2>float('inf'):
                        min2=min1
                    min1=r.val
                f(r.left)
                f(r.right)
        f(root)
        if min2!=float('inf'):
            return min2
        else:
            return -1
```
