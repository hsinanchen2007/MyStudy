### 解题思路
递归回溯

### 代码

```python3
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res = []
        if not root: 
            return res
        def helper(root, sum, track):
            if not root:
                return
            if not root.left and not root.right and sum - root.val == 0:
                track += [root.val]
                res.append(track)
            helper(root.left, sum - root.val, track + [root.val])
            helper(root.right, sum - root.val, track + [root.val]) 
        helper(root, sum, [])
        return res
```