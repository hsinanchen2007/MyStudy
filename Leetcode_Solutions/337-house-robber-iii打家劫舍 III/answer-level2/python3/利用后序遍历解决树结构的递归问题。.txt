### 解题思路
相比起打家劫舍1的线性结构和2的环状结构，本题的树形结构更为复杂。因为问题从简单的递推变成了逆向的递归。
即先从树的叶节点开始，一层一层向上推，到根结点结束。利用后序遍历可以将问题分解为一个父节点和两个子节点的子问题。
后序遍历又递归函数`postOrderTraversal()`实现，此外利用了`defaultdict`来构建字典存放各结点的DP值。


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
class Solution:
    def rob(self, root: TreeNode) -> int:
        if root == None:
            return 0
        else:
            self.dp = defaultdict(lambda: [None, None])
            self.postOrderTraversal(root)
            return max(self.dp[root])

    def postOrderTraversal(self, node):
        if node == None:
            return
        else:
            self.postOrderTraversal(node.left)
            self.postOrderTraversal(node.right)
            if node.left == None and node.right == None:
                self.dp[node][0] = 0
                self.dp[node][1] = node.val
            elif node.left != None and node.right == None:
                self.dp[node][0] = max(self.dp[node.left])
                self.dp[node][1] = self.dp[node.left][0] + node.val
            elif node.right != None and node.left == None:
                self.dp[node][0] = max(self.dp[node.right])
                self.dp[node][1] = self.dp[node.right][0] + node.val
            elif node.left != None and node.right != None:
                self.dp[node][0] = max(self.dp[node.left]) + max(self.dp[node.right])
                self.dp[node][1] = self.dp[node.left][0] + self.dp[node.right][0] + node.val



        
```