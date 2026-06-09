```
public int maxDepth(TreeNode root){
     if(root == null) return 0;
     return Math.max(maxDepth(root.left),maxDepth(root.right))+1;
 }
```
**递归**
当结点为空的时候返回零。

根节点的最大深度是左子树或右子树中深度的最大值加1；左子树的最大深度是他的左子树深度或右子树深度加1，右子树最大深度是左子树或右子树深度最大值加1。一直递归到结点为空的时候找到出口