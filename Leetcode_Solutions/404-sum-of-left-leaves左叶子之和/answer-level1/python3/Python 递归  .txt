这题有点意思，推荐大家练练。有些小细节不注意，特别容易错误。一开始审题没看好，写了个所有左边节点和的答案。。光看一个例子容易想当然。

思路是用变量res存满足要求的叶子节点的值，不断更新。

```
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        self.res=0
        def sumof(root):
            if not root:           
                return
            if root.left and not root.left.right and not root.left.left:       
                self.res+=root.left.val
            sumof(root.left)
            sumof(root.right)
        sumof(root)
        return self.res
        
```
