### 解题思路
- 算法思路：求p节点的路径，q节点的路径，再求两路径上最后一个相同的节点。
- 分类:
    - 一个节点是另一个节点的祖先的情况
    - 两个节点有共同祖先的情况

- 说明：本人水平较菜，代码逻辑并不优美，请见谅。

### 代码

```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        res = []
        path = []
        self.func(root,res,path,p,q)
        if len(res) == 1:  #一个节点是另一个节点的祖先的情况
            return res[0][-1]

        #两个节点有共同祖先的情况
        size = len(res[0]) if len(res[0])<len(res[1]) else len(res[1])
        s = []
        for i in range(size):
            if res[0][i] == res[1][i]:
                s.append(res[0][i])
        return s[-2]

        return res
    def func(self,root,res,path,p,q):
        if root is None:
            return 
        path.append(root)
        if root == p or root == q:
            res.append(path[:])
            return 
        
        self.func(root.left,res,path,p,q)
        self.func(root.right,res,path,p,q)
        path.pop() 

```







