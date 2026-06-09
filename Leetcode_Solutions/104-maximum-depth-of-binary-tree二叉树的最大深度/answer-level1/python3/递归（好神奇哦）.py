### 解题思路
需要看迭代！！！
![image.png](https://pic.leetcode-cn.com/fce9b5ba2583fa238c2474e63cd8f0e547866074fa5cdcaad5e653313aa8d0da-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right)) # 相当于每运行一次maxDepth函数就+1,最初的root属于第一层，所以预先1+
```