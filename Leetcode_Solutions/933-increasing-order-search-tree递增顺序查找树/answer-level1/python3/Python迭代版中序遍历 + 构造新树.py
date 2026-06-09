利用栈来模拟中序遍历的递归过程， 然后再建立一个新树

```python []
def increasingBST(root):
    if root:
        stack = []
        data = []

        # 模拟中序遍历过程
        while stack or root:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                data.append(root.val)
                root = root.right
        
        # 构造一颗新树
        ans = cur = TreeNode(None)
        for v in data:
            cur.right = TreeNode(v)
            cur = cur.right
        return ans.right
```

