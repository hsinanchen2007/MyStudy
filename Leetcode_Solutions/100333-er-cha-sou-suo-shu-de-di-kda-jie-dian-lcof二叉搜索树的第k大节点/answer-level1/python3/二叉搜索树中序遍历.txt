### 解题思路
二叉搜索树中序遍历，即可按照val从小到大进行遍历，输出需要的第K大数
![下载 (6).png](https://pic.leetcode-cn.com/7dd35cf6db35ed80e8840fa374c3b4c59a1292af85ed9b0b3e9089bbd821a25d-%E4%B8%8B%E8%BD%BD%20\(6\).png)

### 代码

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        ans = []
        def fuc(root):
            if not root :
                return 0
            fuc(root.left)
            ans.append(root.val)
            fuc(root.right)
        fuc(root)
        return ans[-k]
```