```
        def traverse(root):
            stack = []
            while stack or root:
                while root:
                    stack.append(root)
                    root = root.left
                root = stack.pop()
                if not root.left and not root.right:
                    yield root.val
                root = root.right

        iter1 = traverse(root1)
        iter2 = traverse(root2)
        a, b = next(iter1, None), next(iter2, None)
        while a is not None and b is not None and a == b:
            a, b = next(iter1, None), next(iter2, None)

        return a == b
```


然鹅并没有多快。

![image.png](https://pic.leetcode-cn.com/20714c702b655adfab15a31597c359e1a8d94bdcd578e788b9f977e086990c39-image.png)
