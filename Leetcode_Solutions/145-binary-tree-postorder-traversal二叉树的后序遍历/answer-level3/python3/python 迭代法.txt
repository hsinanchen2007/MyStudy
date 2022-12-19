本来不知道后序遍历是什么，试了下输出结果发现是“根->右->左”然后reverse。

既然说递归很简单那就尝试下迭代法，backto用来记住返回时的左子叶。

```python []
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if root==None:
            return []
        cur=root
        res=[]
        backto=[]
        backto.append(None)
        while cur!=None:
            res.append(cur.val)
            if cur.left!=None:
                backto.append(cur.left)
            if cur.right!=None:
                cur=cur.right
            else:
                cur=backto.pop()
        res.reverse()
        return res        
```
