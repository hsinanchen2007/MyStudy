### 解题思路
![平衡二叉树.png](https://pic.leetcode-cn.com/6c75be145a273944ee591f14da9a9f3b805aed729cd09e270f2b6b0885b0940d-%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91.png)

我们可以设想二叉树的每一个叶节点都有虚拟的左孩子和右孩子，并且每一个虚拟节点的深度为1
那么，二叉树的每一个叶节点的深度就是2，我们在深度优先遍历时，如果到达了叶节点或者虚拟节点，就返回该节点的深度
在函数的最后一行，我们返回当前节点的左孩子最大深度与右孩子最大深度的最大值加1，即当前节点的最大深度
```
return max(left, right)+1
```
这里left是左孩子的最大深度，right是右孩子的最大深度
```
left = method(N.left)
right = method(N.right)
```

在返回节点最大深度之前，我们加一个判断，如果出现了|left-right| > 1，说明已经存在子树不平衡，返回False

亦或者，如果left和right中已经出现了False，我们直接返回False

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def method(N):
            if not N:
                return 1
            if N.left is None and N.right is None:
                return 2
            left = method(N.left)
            right = method(N.right)
            if not left or not right:
                return False
            if abs(left-right) > 1:
                return False
            return max(left, right)+1
        return method(root)

```