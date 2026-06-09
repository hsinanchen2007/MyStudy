### 解题思路
卧槽尼玛，都递归了你列表还搁这引用呢？
等👴起来，分分钟搞个新编程语言把宁市场份额全部占了。
一个聪明的语言应该可以显示指明对象或类型是否为引用或传递。
Python快爬开快爬开。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, s: int) -> List[List[int]]:
        res = []

        def dfs(root, arr):
            if root:
                if not root.left and not root.right:
                    if sum(arr) + root.val == s:
                        arr.append(root.val)
                        res.append(arr)
                else:
                    arr1, arr2 = copy.copy(arr), copy.copy(arr)
                    arr1.append(root.val)
                    arr2.append(root.val)
                    if root.left:
                        dfs(root.left, arr1)
                    if root.right:
                        dfs(root.right, arr2)

        search(root, [])
        return res
```