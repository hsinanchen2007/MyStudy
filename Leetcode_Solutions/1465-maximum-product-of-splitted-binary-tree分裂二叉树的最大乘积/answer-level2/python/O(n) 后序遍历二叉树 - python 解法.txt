### 解题思路

本质上是把一组整数分成两组，让两组的和的乘积最大。分裂二叉树的具体方法就是从树上拿出一个子树来。

尽量让两组和接近可以得到最大乘积。

先求所有节点的和。

然后再遍历整棵树，看哪个子树的和与所有节点和的一半最接近。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        self.sum = 0
        self.cur_t = 0
        def get_sum(r):
            if r:
                self.sum += r.val
                if not r.left and not r.right:
                    self.cur_t = r.val
                else:
                    get_sum(r.left)
                    get_sum(r.right)
        get_sum(root)
        self.target = self.sum/2
        self.cur_x = abs(self.target-self.cur_t)
        def find_tar(r):
            if r:
                s = r.val
                s += find_tar(r.left)
                s += find_tar(r.right)
                cur_x = abs(s - self.target)
                if  cur_x < self.cur_x:
                    self.cur_t = s
                    self.cur_x = cur_x
                return s
            else:
                return 0
        find_tar(root)
        return ((self.sum - self.cur_t) * self.cur_t) % 1000000007
```