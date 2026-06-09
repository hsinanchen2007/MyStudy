### 解题思路
关键还是要想清楚为啥可以这样写。

左叶子节点最好在上一个节点就处理掉，否则到了下一个节点就无法判断是不是叶子节点了啊。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        result = 0
        if root == None:
            return 0
        if root.left:
            if not root.left.left and not root.left.right:
                result += root.left.val
            else:
                result += self.sumOfLeftLeaves(root.left)
        if root.right:
            result += self.sumOfLeftLeaves(root.right)
        
        # 对 root != None 但 root.left root.right 都是空，也返回 0
        return result
```