
```递归实现 []
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        list = []
        if root is None:                          #基准条件
            return []
        list += self. inorderTraversal(root.left) #先把左节点加入
        list.append(root.val)                     #添加根节点
        list += self. inorderTraversal(root.right)#添加右节点  
        return list
```

```栈实现 []
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        stack = []
        p = root
        out = []
        while p or stack:        #p 游标 有 右边的值 或 栈 还有元素
            while p:
                stack.append(p)  #p 游标加入栈, 一直去找子节点的左节点是否存在,全部压入栈
                p = p.left
            item = stack.pop()   #把 当前 最左侧的 元素弹出来
            out.append(item.val) #添加到输出list里
            p = item.right       #再看右节点需要不需要迭代
        return out
        
```