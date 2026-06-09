### 解题思路
前序遍历：按照框架我们只需要知道如何对当前的节点进行处理即可
我们每次遍历到一个节点，将其左结点置空，然后连接点新建节点的右边即可
这一种思路就是在遍历的同时进行操作如下图
![image.png](https://pic.leetcode-cn.com/bba80e2ee3727eb30c333c01c606e795ffe21f579cda160167e592b421d14dd7-image.png)

还有一种思路，就是先中序遍历（我给出的迭代的版本），然后根据遍历结果进行建树

两种方法大同小异

### 代码（递归的同时进行建树）

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        ans = TreeNode(None)
        temp = ans
        def help(root):
            nonlocal temp
            if root is None:
                return 
            help(root.left)
            root.left = None
            temp.right = root
            temp = temp.right
            help(root.right)
        
        help(root)

        return ans.right

```

### 代码 （遍历结束进行建树）
```python 3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
    
        stack, output = [], []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            output.append(root.val)
            root = root.right

        ans = TreeNode(None)
        temp = ans
        for val in output:
            node_val = TreeNode(val)
            temp.right = node_val
            temp = temp.right
        return ans.right
```