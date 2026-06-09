### 解题思路
借助一个栈，对二叉树进行右节点优先的前序遍历
最后返回前序遍历的逆序
### 代码

```python3
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        stack = [root]
        res = []
        i = 0
        while stack:
            cur = stack.pop()
            res.append(cur.val)
            if cur.left:
                stack.append(cur.left)
            if cur.right:
                stack.append(cur.right)
        return res[::-1]
```