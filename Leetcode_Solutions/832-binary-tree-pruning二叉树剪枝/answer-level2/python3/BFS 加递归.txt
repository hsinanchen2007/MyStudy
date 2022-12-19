### 解题思路
树的题目一般都可以递归来做，递归的话首先要考虑base case, 其他的交给递归。这里的base case 显然是root跟节点，树的递归base case基本都是跟
。考虑根节点，我们需要考虑z什么情况下删除节点，当左子树全是零可以删除，因此定义一个函数来确定一棵树是否全是0.右子树同上，代码如下。
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        #遍历子树，如果有加起来的和为=0则可以删除
        def help(root):#定义一个函数通过BFS来求一个树的所有元素和
            flag=0
            if root is None:
                return flag
            queue=[root]
            while queue:
                node=queue.pop(0)
                flag+=node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            return flag
        if root is None:#考虑特例
            return None
        if  not help(root.left):#base case 如果树左子树的所有元素均为0，则可以删除左子树
            root.left=None
        else:
            root.left=self.pruneTree(root.left)#否则的话用递归
        if not help(root.right):
            root.right=None
        else:
            root.right=self.pruneTree(root.right)
        return root
        
```