这道题值得再写一遍，因为一点细节卡了很久。首先是准备工作，先回顾一下如何判断两棵树完全相同

```python
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
            if p==None and q==None: return(True)
            if p==None or q==None: return(False)
            if p.val != q.val: return(False)
            return(self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right))
```

原题逻辑：需要两个函数 (1)dfs搜索，发现A的某一节点值和Broot值相同时开始判断B是不是A的子结构 (2)判断子结构

解决方案：

1. 因为dfs递归的返回值很绕很头晕，所以我宁愿加入一个初始值为FALSE的self.flag变量来记录存在子结构相同，最后直接去return这个值

2. 我自己认为最恶心的地方在于子结构不是子树，最初大意忽略这一点debug好久，子结构判断方式如下，和子树有区别。主要是如何判断为TRUE

```python
        def isSub(p,q):
            if q == None: return(True)
            if p == None: return(False)
            if p.val != q.val: return(False)
            return(isSub(p.left,q.left) and isSub(p.right,q.right))
```
全部代码
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.flag = False
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if B==None:
            return(False)
        #dfs子函数，实现判断两棵树是否相同
        def isSameTree(p,q):
            if q == None: return(True)
            if p == None: return(False)
            if p.val != q.val: return(False)
            return(isSameTree(p.left,q.left) and isSameTree(p.right,q.right))
    
        def dfs(root):
            if root == None:
                return 
            #如果搜索到某个节点和Broot相同，则开始判断
            if root.val == B.val:
                if isSameTree(root,B)==True:
                    self.flag = True
            #如果根节点相同但是树不一样，则继续向下搜索
            dfs(root.left)
            dfs(root.right)
            return(self.flag)
        return(dfs(A))
```