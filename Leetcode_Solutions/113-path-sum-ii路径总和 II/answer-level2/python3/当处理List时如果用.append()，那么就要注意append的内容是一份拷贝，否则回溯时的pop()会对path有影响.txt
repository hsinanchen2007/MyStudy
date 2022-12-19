### 解题思路
看了很多人都是用+=来处理list,这样的好处是每一次进入下一个节点时自动拷贝了一份path的引用。其实append也可以，这样回溯时就会有Pop()，流程比较标准。
特别注意的就是，当处理List时如果用.append()，那么就要注意append的内容是一份拷贝，否则回溯时的pop()会对path有影响。

另外一个注意点就是
```
if root.left is None and root.right is None and sum-root.val == 0:
    res.append(path.copy())
```
这里不需要return

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        path=[]
        def dfs(root,sum):
            if root is None:
                return 

            path.append(root.val)

            if root.left is None and root.right is None and sum-root.val == 0: 
                res.append(path.copy()) 

            dfs(root.left,sum-root.val)
            dfs(root.right,sum-root.val)
            path.pop()
        res = []
        dfs(root,sum)
        return res
```