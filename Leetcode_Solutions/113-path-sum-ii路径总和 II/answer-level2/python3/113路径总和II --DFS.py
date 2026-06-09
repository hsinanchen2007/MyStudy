### 解题思路
和112题一样，是先序遍历（DFS）
1.用sums依次减去节点的值，直到叶子节点的值为sums
2.设置辅助变量res，初始为0，一直加到叶子节点时，`res+root.val==sums`
### 代码 --1.依次相减

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sums: int) -> List[List[int]]:
        #对112路径总和的扩展，要求返回所有的路径
        if not root:return []
        def hasChild(x):
            return x.left or x.right
        
        path=[]
        def DFS(root,temp,sums):
            if not root:return []
            if not hasChild(root) and root.val==sums:#当到叶子节点时，root.val==sums
                temp+=[root.val]#append不能处理None的情况
                path.append(temp)#将一种可能添加到路径
                #!return绝对不能加返回！只能在全部扫描结束后才能返回
            DFS(root.left,temp+[root.val],sums-root.val)
            DFS(root.right,temp+[root.val],sums-root.val)
        DFS(root,[],sums)
        return path
```
### 代码 --2.加辅助变量，依次相加
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sums: int) -> List[List[int]]:
        #对112路径总和的扩展，要求返回所有的路径
        if not root:return []
        def hasChild(x):
            return x.left or x.right
        res=0
        path=[]
        def DFS(root,temp,res):
            if not root:return []
            if not hasChild(root) and sums-root.val==res:#当到叶子节点时，root.val==sums
                temp+=[root.val]#append不能处理None的情况
                path.append(temp)#将一种可能添加到路径
                #!return绝对不能加返回！只能在全部扫描结束后才能返回
            DFS(root.left,temp+[root.val],res+root.val)
            DFS(root.right,temp+[root.val],res+root.val)
        DFS(root,[],res)
        return path
```