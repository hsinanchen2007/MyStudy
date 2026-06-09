本题比赛中的示例 5 刚开始是有问题的：

> 示例 5：
>
> 输入：root = [1,2,3], target = 2
> 输出：[1,2,3]

让我犹豫了一会。

后来这个 target 改成 1 就对了。

也不难

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        def del_t(t):
            if t.left:
                if del_t(t.left):
                    t.left = None
            if t.right:
                if del_t(t.right):
                    t.right = None
            if not t.left and not t.right:
                if t.val == target:
                    return True
            return False
        if del_t(root):
            return None
        return root
```