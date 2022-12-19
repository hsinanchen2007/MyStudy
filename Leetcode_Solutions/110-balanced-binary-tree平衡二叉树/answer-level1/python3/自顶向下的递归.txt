### 解题思路
![image.png](https://pic.leetcode-cn.com/3af05ab57897547616e1b775e9fc8d2eddbe3926285467917a789ccc7f116231-image.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root: return True
        return abs(self.height(root.left) - self.height(root.right)) <= 1 \
        and self.isBalanced(root.left) \
        and self.isBalanced(root.right) # 要继续往下排查，不能只看当前的abs<=1

    def height(self, root):
        if not root: return 0 # 如果root为空，高度就是0 （不明白为啥官方说-1）
        # if not root.left and not root.right: # root为叶子节点，高度是1
        #     return 1
        # elif not root.left and root.right: # 只有右节点，那就是右节点的高度+1
        #     return 1 + self.height(root.right)
        # elif root.left and not root.right: # 只有左节点，左节点的高度+1
        #     return 1 + self.height(root.left)
        # else: # 左右节点都有
        return 1 + max(self.height(root.left), self.height(root.right))
```