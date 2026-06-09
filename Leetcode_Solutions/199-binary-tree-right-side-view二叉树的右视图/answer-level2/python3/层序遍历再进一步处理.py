### 解题思路
层序遍历得到二维数组，外层数组的每个元素是树每层元素从左至右组成的列表，进一步处理把每个数组替换为数组最后一个元素即可

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return
        else:
            res = []
            queue = [root]
            while queue:
                size = len(queue)
                temp = []
                for i in range(size):
                    r = queue.pop(0)
                    temp.append(r.val)
                    if r.left:
                        queue.append(r.left)
                    if r.right:
                        queue.append(r.right)
                res.append(temp)
            for i in range(len(res)):
                res[i] = res[i][-1]
            return res





```