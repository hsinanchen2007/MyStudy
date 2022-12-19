### 解题思路
**递归Python，32ms**
代码比较简单，一看就懂
使用一个dict存储每一层的节点值key=层数，value=[值]
根据先left后right的方法就行，
最后根据key排序。
Python大法好，比其他的简洁多了。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        
        if not root:
            return []
        res = {}

        def dfs(r, n):
            if n in res:
                res[n].append(r.val)
            else:
                res[n] = [r.val]
            if r.left:
                dfs(r.left, n + 1)
            if r.right:
                dfs(r.right, n + 1)

        dfs(root, 1)
        # print(res)
        result = [res[k] for k in sorted(res.keys(),key=lambda x:x, reverse=True)]
        return result
```