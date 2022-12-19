## 思路:

二叉搜索树**中序遍历**，是按大小排序的

- 递归
- 迭代（栈）

时间复杂度都是：$O(k)$

递归

```python
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        res = None
        def helper(root):
            nonlocal k, res
            if root.left: helper(root.left)
            k -= 1
            if k == 0: 
                res = root.val
                return 
            if root.right: helper(root.right)
        helper(root)
        return res
```

迭代

```python
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        cur = root
        stack = []
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            tmp = stack.pop()
            k -= 1
            if k == 0:
                return tmp.val
            if tmp.right:
                cur = tmp.right
```


