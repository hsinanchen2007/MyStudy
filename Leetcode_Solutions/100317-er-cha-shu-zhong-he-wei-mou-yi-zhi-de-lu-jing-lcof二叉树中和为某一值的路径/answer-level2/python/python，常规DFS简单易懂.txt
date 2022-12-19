### 解题思路
探测二叉树的每个节点，沿途记录路径列表和累和，并判断：
- 节点是叶节点且累加和刚好满足要求，则沿途列表加入到结果列表
- 否则，继续对可能的左右子节点递归探测

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum_: int) -> List[List[int]]:
        def path(root, sum_, lyst):
            if not root.left and not root.right and sum_ == root.val:
                res.append(lyst[:]+[root.val])
            if root.left:
                path(root.left, sum_-root.val, lyst+[root.val])
            if root.right:
                path(root.right, sum_-root.val, lyst+[root.val])
        res = []
        if root:
            path(root, sum_, [])
        return res
```
欢迎关注个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)