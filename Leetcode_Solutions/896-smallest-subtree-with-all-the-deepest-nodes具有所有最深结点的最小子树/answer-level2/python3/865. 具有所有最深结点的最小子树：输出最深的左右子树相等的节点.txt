![image.png](https://pic.leetcode-cn.com/e26d9527922d8b37fdc361fc0716751c46f18d771de6c6161c2f895b8bb808ee-image.png)

![image.png](https://pic.leetcode-cn.com/6ee599a817fea09d5031066661c2ff765cb2dbb73e7df0672f4fbad0c9544447-image.png)

40ms，100%，遍历树，当节点的左右子树深度相等且对应深度超过当前答案的时候，修改答案的和对应深度。

```python []
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        ans, ans_dep = None , 0
        def f(root, i):
            if not root:
                return i
            l_dep = f(root.left, i + 1)
            r_dep = f(root.right, i + 1)
            nonlocal ans, ans_dep
            if l_dep == r_dep and l_dep >= ans_dep:
                ans = root
                ans_dep = l_dep
            return max(l_dep, r_dep)
        f(root, 0)
        return ans
```


另外官解用了一种高级数据结构，非常酷炫，学习了，但也可以直接用解包的元组来做，速度上官解最慢，因为返回最复杂，其次是我写的这种二元返回，最快的还是全局修改。

```python []
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def f(root):
            if not root:
                return None, 0
            l, r = f(root.left), f(root.right)
            if l[1] > r[1]:
                return l[0], l[1] + 1
            elif l[1] < r[1]:
                return r[0], r[1] + 1
            else:
                return root, r[1] + 1
        return f(root)[0]
```
