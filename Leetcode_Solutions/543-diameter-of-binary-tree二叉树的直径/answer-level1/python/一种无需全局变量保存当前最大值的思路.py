### 解题思路
一种无需全局变量保存当前最大值的思路。

一个根节点下的直径有3种可能：
1、直径在左子树内部，不经过根节点
2、直径在右子树内部，不经过根节点
3、直径经过当前根节点，且直径为两个子树深度之和

分别对左右子树递归调用，返回左右子树的直径和深度
那么当前节点的直径为 max(左直径，右直径，左深度+右深度)，当前节点深度为 max(左深度，右深度)+1
再将直径和深度返回给上一层

递归结束的条件是到达空节点，直接返回 0,0
![image.png](https://pic.leetcode-cn.com/64601bfc481eaadc16d4fafc1e6065a2c438de374083d95e055984578e9692fd-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:

        def recursion(node):
            if not node:
                return 0,0
            max_len_left,deep_left = recursion(node.left)
            max_len_right,deep_right = recursion(node.right)
            manx_len = max(max_len_left, max_len_right, deep_left+deep_right)
            deep = max(deep_left,deep_right) + 1
            return manx_len,deep

        return recursion(root)[0]
```