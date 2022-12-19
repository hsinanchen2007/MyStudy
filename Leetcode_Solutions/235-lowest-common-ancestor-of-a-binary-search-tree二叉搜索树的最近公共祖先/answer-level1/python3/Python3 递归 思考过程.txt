### 思考过程
1. 题目要求为最近的公共祖先，首先想到的是普通二叉树的做法，分别记录从`root`遍历到 `p` `q`节点的祖先，对比得到最近公共祖先
2. 但是这道题为BST，分析BST特征，左树比当前节点小，右树比当前节点大。可以想到，我们可以容易的判断`p`,`q`在当前节点的哪一侧。
3. 如果再同侧，则再往下层递归，如在两侧，则返回当前节点
4. 注意一下边界条件，得出代码：

```
class Solution:    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left, p ,q)
        elif p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor(root.right, p ,q)
        else:
            return root
```
