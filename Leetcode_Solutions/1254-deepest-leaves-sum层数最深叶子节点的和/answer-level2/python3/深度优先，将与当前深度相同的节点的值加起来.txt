执行用时 :160 ms, 在所有 python3 提交中击败了100.00%的用户
内存消耗 :14.6 MB, 在所有 python3 提交中击败了100.00%的用户

### 解题思路
深度优先：
1. 设置dep变量来记录当前的深度；
2. 将节点的值按照dep键存放；
3. 返回键值最大的那个数。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deepestLeavesSum(self, root):
        dep = 0
        sum = dict()
        stack = list()
        stack.append(root)
        while stack:
            node = stack[-1]
            if dep not in sum:
                sum[dep] = node.val
            else:
                sum[dep] += node.val
            if node.left:
                dep += 1
                stack.append(node.left)
                node.left = None
                continue
            elif node.right:
                dep += 1
                stack.append(node.right)
                node.right = None
                continue
            else:
                dep -= 1
                stack.pop()
        return sum[max(sum)]
```