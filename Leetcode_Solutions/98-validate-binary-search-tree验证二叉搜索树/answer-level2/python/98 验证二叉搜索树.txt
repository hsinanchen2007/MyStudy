### 解题思路
利用中序遍历的方法、递归实现

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        res = []
        def dfs(root):
            if not root:
                return
            # 按照 左-打印-右的方式遍历 
            dfs(root.left)
            res.append(root.val)
            dfs(root.right)
        dfs(root)
        # return res

        for i in range(1,len(res)):
            if res[i] <= res[i-1]:
                return False
        return True

```


### 解题思路
利用中序遍历的方法、迭代实现

### 代码

```python
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        res = []
        stack = []
        while stack or root:
            # 不断往左子树方向走，每走一次就将当前节点保存到栈中
            # 这是模拟递归的调用
            if root:
                stack.append(root)
                root = root.left
            # 当前节点为空，说明左边走到头了，从栈中弹出节点并保存
            # 然后转向右边节点，继续上面整个过程
            else:
                tmp = stack.pop()
                res.append(tmp.val)
                root = tmp.right
        # print res, len(res)
        for i in range(1,len(res)):
            if res[i] <= res[i-1]:
                return False
        return True
```