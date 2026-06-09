比较简单，每层按要求变换字符串即可。

```
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        def child(root):
            a=[]
            if root.left:
                a.append(root.left)
            if root.right:
                a.append(root.right)
            return a
        
        def dfs(root,str1):
            if len(child(root))==0:  #递归终点，是没有孩子节点的时候
                str1=str1+str(root.val)  #最后一个不用加箭头
                res.append(str1)
                return
            str1=str1+str(root.val)+'->'  
            for i in child(root):             
                dfs(i,str1)
        res=[]
        if not root:
            return res        
        dfs(root,'')
        return res
```



因为是二叉树的结构，简化了下代码。如下

```
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]: 
        def dfs(root,str1):
            if not root:
                return
            if not root.left and not root.right:
                str1=str1+str(root.val)  
                res.append(str1)
               
            str1=str1+str(root.val)+'->'               
            dfs(root.left,str1)
            dfs(root.right,str1)
            
        res=[]
        if not root:
            return res        
        dfs(root,'')
        return res
```
