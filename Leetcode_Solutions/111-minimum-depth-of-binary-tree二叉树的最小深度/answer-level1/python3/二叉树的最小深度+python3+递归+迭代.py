### 1. 递归
没啥好说的，弄懂题意，直接递归。代码如下：
```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return 1 
        if not root.right:
            return 1+self.minDepth(root.left)
        if not root.left:
            return 1+self.minDepth(root.right)
        return 1+min(self.minDepth(root.left),self.minDepth(root.right))
```
### 2. 迭代（层次遍历）
当某一层有一个叶子节点时，返回当前层的深度(**可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**。代码如下：
```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        ans,count = [root],1
        while ans:
            n = len(ans)
            for i in range(n):
                r = ans.pop(0)
                if r:
                    if not r.left and not r.right:
                        return count
                    ans.append(r.left if r.left else [])
                    ans.append(r.right if r.right else [])
            count+=1       
```
