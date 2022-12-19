### 解题思路
用res来记录，然后用layer记录目前是在哪一层
res先记下的是TreeNode，遍历完了才会转成val

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> [[int]]:
        if root is None:
            return []
        # 我想的是我存进去整层节点，然后每次都逆序遍历节点下所有的
        res = [[root]]
        layer = 1
        while res[-1]:
            res.append([])
            if layer % 2 == 1:
                for i in range(len(res[layer - 1]) - 1, -1, -1):
                    if res[layer - 1][i].right:
                        res[layer].append(res[layer - 1][i].right)
                    if res[layer - 1][i].left:
                        res[layer].append(res[layer - 1][i].left)
                    res[layer - 1][i] = res[layer - 1][i].val
            else:
                for i in range(len(res[layer - 1]) - 1, -1, -1):
                    if res[layer - 1][i].left:
                        res[layer].append(res[layer - 1][i].left)
                    if res[layer - 1][i].right:
                        res[layer].append(res[layer - 1][i].right)
                    res[layer - 1][i] = res[layer - 1][i].val
            layer += 1
        res.pop()
        return res
```