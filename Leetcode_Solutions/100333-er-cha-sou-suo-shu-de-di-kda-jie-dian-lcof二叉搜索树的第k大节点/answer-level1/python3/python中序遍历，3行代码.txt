### 解题思路
先得到中序遍历结果，然后返回倒数第K个值。
如果按照右-根-左实现逆中序遍历也可，那么就是返回正数第k个值。
![image.png](https://pic.leetcode-cn.com/56d9f31ea32ea28750c47aa647a2d5714f79c9c19556bccb32efa8a71da7ff58-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        def helper(root):
            return helper(root.left) + [root.val] + helper(root.right) if root else []
        return helper(root)[-k]
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)