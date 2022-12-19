### 解题思路
![image.png](https://pic.leetcode-cn.com/c77dc39e61fdc2c2480347769ac719f6d35bcac639a3d0fc8292d1b20ef583b7-image.png)
- 由于给定我们的是二叉搜索树,我们要利用好这个特性,知道二叉搜索树的特性是位于左子树的节点都比父节点小,位于右子树的节点都比父节点大
- 更具这个特性我们从根节点开始遍历,**从上到下找到第一个在两个输入节点值之间的节点就是最近的公共祖先**
1. 如果当前节点的值比给定两个节点的值都小,那么可以肯定的是公共祖先一定存在于当前节点的右子树中,继续在右子树中寻找
2. 如果当前节点的值比给定两个节点的值都大,那么可以肯定的是公共祖先一定存在于当前节点的左子树中,继续在左子树中寻找
3. 如果当前节点的值在给定两个节点之间,这就是我们要找的公共祖先,返回即可

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if p.val > q.val:
            min_, max_ = q.val, p.val
        else:
            min_, max_ = p.val, q.val  
                  
        result = []
        def search(root, p, q):
            if root.val >= p and root.val <= q:
                result.append(root)
                return
            if root.val > p and root.val > q:
                search(root.left, p, q)
            else:
                search(root.right, p, q)
        
        search(root, min_, max_)
        
        return result[0]           
```

### 非递归
![image.png](https://pic.leetcode-cn.com/d451d859c59997ce90f5cbd8461e08dce555349044423b7076a56631605370ce-image.png)

- 思想和上面是一致的,直接撸代码

### 代码
```
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        while root:
            if root.val < q.val and root.val < p.val:
                root = root.right
            if root.val > q.val and root.val > p.val:
                root = root.left
            else:
                return root
```
