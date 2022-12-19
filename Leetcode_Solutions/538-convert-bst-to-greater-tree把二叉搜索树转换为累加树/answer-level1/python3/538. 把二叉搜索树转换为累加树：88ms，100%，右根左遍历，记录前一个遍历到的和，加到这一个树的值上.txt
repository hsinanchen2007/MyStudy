![image.png](https://pic.leetcode-cn.com/ae6cbc92ceacb023df2646288f57ac56a0867226d161cd14f6b39c8442a531c5-image.png)

总的来说就是逆遍历排序树，然后搞个全局变量持续累加，和其他大佬的写法略有不同的是用了nonlocal

```python []
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        pre = 0
        def f(r):
            if r:
                f(r.right)
                nonlocal pre
                r.val += pre
                pre = r.val
                f(r.left)
        f(root)
        return root
```
