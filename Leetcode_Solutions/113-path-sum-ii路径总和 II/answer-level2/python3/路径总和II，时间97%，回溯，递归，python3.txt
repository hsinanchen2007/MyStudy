### 解题思路
![路径总和.png](https://pic.leetcode-cn.com/6d505da781d50860add67b5699778e27a01866b5d9a0c2ba88bb0d5289832048-%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, summ: int) -> List[List[int]]:
        res = []
        def dfs(T, s, temp):
            if not T:
                return
            temp.append(T.val)
            if not T.left and not T.right:
                if s == T.val:
                    # print(temp)
                    res.append(temp[:])
            if T.left:
                dfs(T.left, s-T.val, temp)
            if T.right:
                dfs(T.right, s-T.val, temp)
            del temp[-1]
        dfs(root, summ, [])
        return res
```