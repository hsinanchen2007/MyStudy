### 解题思路

先序遍历，第一个数值是根节点。

如果接下来的 - 数量比这一层的大，那一定是左子树。

因为**如果节点只有一个子节点，那么保证该子节点为左子节点。**

然后找到后面跟这个 - 数量相等的位置，如果找到，这个位置之后的是右子树

如果找不到，那剩下的值都是左子树的值。

然后递归生成树就可以了


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import re
class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        def recursion(depths, values):
            if len(depths) == 0:
                return None
            node = TreeNode(values[0])
            if len(depths) > 1:
                if depths[1] not in depths[2:]:
                    node.left = recursion(depths[1:], values[1:])
                else:
                    idx = depths[2:].index(depths[1])
                    node.left = recursion(depths[1: idx+2], values[1: idx+2])
                    node.right = recursion(depths[idx+2:], values[idx+2:])
            return node
        depths = list(map(len, re.split('\d+', S)))[:-1]
        values = list(map(int, re.split('-+', S)))
        return recursion(depths, values)
```