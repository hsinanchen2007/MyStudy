### 解题思路
从底向上，一遍递归实现。
其中辅助函数用于记录当前节点(是否平衡、深度)，最后返回root节点结果即可。

### 结果
![image.png](https://pic.leetcode-cn.com/870f09679c84091259446e796129a2cae29c0d0b58c78a957b5bdb666fd96a2f-image.png)

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
        def helper(root):
            if not root:
                return (True, 0)
            l, r = helper(root.left), helper(root.right)
            return (abs(l[1] - r[1])<2 and l[0] and r[0], max(l[1], r[1])+1)
        return helper(root)[0]
```
欢迎关注个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)