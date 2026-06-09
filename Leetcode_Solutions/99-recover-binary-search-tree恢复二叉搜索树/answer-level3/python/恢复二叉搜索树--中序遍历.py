### 解题思路
一个二叉搜索树中序遍历后是一个有序的数字，举个例子
> [1, 2, 3, 4, 5, 6, 7, 8, 9]

现在我们4和8变成
>[1, 2, 3, 8, 5, 6, 7, 4, 9]

再来模拟一遍中序遍历，当碰到后一个元素小于一个元素的时候，即pre=8, cur=5的时候，记录一下pre，然后继续走，当pre=7, cur=4的时候，我们记录一下cur=4，最后交换一下连个节点的值就行了
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        x = y = pre = None
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()

            if pre and root.val < pre.val:
                y = root
                if x is None:
                    x = pre
                else:
                    break
            pre = root
            root = root.right

        x.val, y.val =  y.val, x.val

```
##### 中序遍历递归版本
```python3 中序遍历递归版本
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        x=y=pre=None
        def help(root):
            nonlocal x,y,pre
            if root is None:
                return 
            help(root.left)
            if pre and pre.val>root.val:
                y = root
                if x is None:
                    x = pre
                else:
                    return
            pre = root
            help(root.right)
        help(root)
        x.val, y.val = y.val, x.val

```