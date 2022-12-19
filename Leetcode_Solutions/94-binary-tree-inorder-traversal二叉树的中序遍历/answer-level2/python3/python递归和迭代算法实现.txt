### 递归解题思路
中序遍历的顺序：left=>node=>right
利用递归函数实现此存入顺序，当root的值为int类型，将值存入全局列表。

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
        self.results = []
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        if isinstance(root, int):
            self.results.append(root)
            return
        if root.left is not None:
            self.inorderTraversal(root.left)
        if root.val is not None:
            self.inorderTraversal(root.val)
        if root.right is not None:
            self.inorderTraversal(root.right)
        return self.results
```

### 迭代解题思路
迭代算法要比递归算法多考虑存值顺序的实现
中序遍历的顺序：left=>node=>right
利用deelListMaker函数拆分TreeNode，left直接放在数组顶端，node和right的存储位置根据left的值视情况而定。

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
        self.deelList = []
    def deelListMaker(self, item):
        index=0
        if isinstance(item, int):
            self.result.append(item)
            return 
        if isinstance(item.left, TreeNode):
            self.deelList.insert(0,item.left)
            index=1
        self.deelList.insert(index,item.val)
        if isinstance(item.right, TreeNode):
            self.deelList.insert(index+1,item.right)
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        self.deelListMaker(root)
        while len(self.deelList)>0:
            self.deelListMaker(self.deelList.pop(0))
        return self.result
```