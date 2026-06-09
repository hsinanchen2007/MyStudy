### 解题思路
思路比较简单，就是搜索左右子树，返回左右子树的深度，取较小的值即可。```return 1+min(left,right)```


需要注意的特殊处理：
当二叉树的结构为[1,2]，也就是根节点带一个子节点时，上述思路造成最小深度为0的情况，因为None会返回0。
1. 当左子树为空，返回右子树的深度。
2. 当右子树为空，返回左子树的深度。


```py
if left == 0:return 1+right
elif right ==0:return 1+left
```

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:return 0
        def dfs(node):
            if not node:return 0
            left = dfs(node.left)
            right = dfs(node.right)
#           当左子树为空
            if left == 0:return 1+right
#           当右子树为空
            elif right ==0:return 1+left
            else:return 1+min(left,right)

        return  dfs(root)
```