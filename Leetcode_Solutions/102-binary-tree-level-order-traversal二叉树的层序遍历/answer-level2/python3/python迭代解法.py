### 解题思路
将TreeNode一层层的拆解为左节点和右节点，父节点的值直接放入result数组中。
相同层级的值需要放在同一个列表中然后存入result，通过给第一个父节点传入index，依次传递index的递增值来区分存入result的第几个列表中。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.result = []
        self.traversalList = []
    def traversalMaker(self, item):
        if item is None:
            return
        if len(self.result) < item.index+1:
            self.result.append([])
            self.result[item.index].append(item.val)
        else:
            self.result[item.index].append(item.val)
        if item.left is not None:
            item.left.index = item.index + 1
            self.traversalList.append(item.left)
        if item.right is not None:
            item.right.index = item.index + 1
            self.traversalList.append(item.right)
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        root.index = 0
        self.traversalMaker(root)
        while len(self.traversalList)>0:
            item = self.traversalList.pop(0)
            self.traversalMaker(item)
        return self.result
```