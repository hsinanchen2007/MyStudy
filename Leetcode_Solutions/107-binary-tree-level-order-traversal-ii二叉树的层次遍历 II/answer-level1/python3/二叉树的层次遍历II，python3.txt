### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        layerorder = [[root,1]]
        res = []
        i = 0
        while i < len(layerorder):
            if layerorder[i][0].left:
                layerorder.append([layerorder[i][0].left, layerorder[i][1]+1])
            if layerorder[i][0].right:
                layerorder.append([layerorder[i][0].right, layerorder[i][1]+1])
            i += 1
        cur_layer = 0
        temp = []
        for i in range(len(layerorder)):
            if layerorder[i][1] != cur_layer:
                cur_layer = layerorder[i][1]
                res.append(temp)
                temp = []
                temp.append(layerorder[i][0].val)
            else:
                temp.append(layerorder[i][0].val)
        res.append(temp)
        res = res[1:]
        res.reverse()
        return res
```