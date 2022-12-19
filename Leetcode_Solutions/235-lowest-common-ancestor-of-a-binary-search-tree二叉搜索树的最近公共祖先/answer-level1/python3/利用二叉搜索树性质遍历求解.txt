
利用二叉搜索树的性质，我们只需要找到第一个val在区间[q,p]的root即可。

遍历方式就是前序遍历

if ：root.val大于p和 q：
    root = root.left

if ：root.val小于p和 q：
    root = root.right

在题目的图片上对照一下很好理解


代码如下 （击败98%）：
```

def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val >= q.val:
            p,q =q,p
        def helper(root):
            if root:
                if  q.val >= root.val >= p.val:
                    return root
                
                elif  p.val   < root.val:
                    return helper(root.left)

                elif  q.val   > root.val:
                    return helper(root.right)
        res = helper(root)
        return res
```
