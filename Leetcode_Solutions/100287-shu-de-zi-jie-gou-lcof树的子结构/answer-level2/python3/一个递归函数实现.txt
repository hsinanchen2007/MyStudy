![image.png](https://pic.leetcode-cn.com/09b51e2f7096960662ab2bb4130714890a6a14ddb82280525d2ae7859fadac91-image.png)

如果a树和b树的当前节点的值相同，那么比较a的左右子树和b的左右子树是否相同
如果a树和b树的当前节点的值不同，那么比较a的左子树和B是否相同，或者比较a的右子树和B是否相同

递归结束条件：
1 b被消耗完，返回True
2 b不为空，a被消耗完，返回False

```
class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if B == None:
            return False
        def back(a, b):
            if b == None:
                return True
            if a == None and b!= None:
                return False
            if a.val == b.val:
                return back(a.left, b.left) and back(a.right, b.right)
            else:
                return back(a.left, B) or back(a.right, B)
        return back(A, B)
```

