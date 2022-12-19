### 解题思路
这几天自己在钻研递归 
我佛了 数的题目我只会用while 还特别麻烦
我宣布我一定要掌握递归

思路就是遍历所有节点 把值一个个去比根节点

用了一个全局变量res
局部变量我发现自己不会用
放在goall()里面的话每次都会重置
干脆把它当参数传进来 然后每次都修改它

遍历的目标就是那个最经典的三明治

谢谢大家 
主要是希望能帮到思路相近的菜鸡们
奥力给
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root :
            return False 
        v=root.val
        res=[]
        goall(root,res)
        for i in (res) :
            if i!= v:
                return False
        return True
def goall(root,res) :
    while not root :
        return 
    res+=[root.val] 
    goall(root.left,res)
    goall(root.right,res)
```