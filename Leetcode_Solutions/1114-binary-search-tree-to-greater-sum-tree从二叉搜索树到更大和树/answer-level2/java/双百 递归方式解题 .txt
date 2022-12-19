**JAVA code
刚上完algs4中的BST，所以代码写的一般。**

递归方法解题，分四步即可。<耗时0ms,内存耗时击败100%用户>
1，对根节点的右子树进行 bstToGst(root.right) 。
2，对根节点的值进行更新，其等于右子树的最左节点的值加上其原有的值。
```
TreeNode t = root.right;
            while(t.left!=null) t = t.left;  # 找到右子树的最左结点
            root.val = root.val + t.val;  
```
3，对根节点的左子树进行 bstTOGst(root.left)
4，将左子树的每个节点的值都加上根节点的值。
```
class Solution {
    public TreeNode bstToGst(TreeNode root) {
        if (root == null) return null;
        if (root.right != null) {
            root.right = bstToGst(root.right);
            TreeNode t = root.right;
            while(t.left!=null) t = t.left;
            root.val = root.val + t.val;
        }
       if (root.left != null) {
           root.left = bstToGst(root.left);
            int plus = root.val;
            root.left = bstplus(root.left, plus);
       }
       return root;
    }

    private TreeNode bstplus(TreeNode x, int i) {
        x.val = x.val + i;
        if (x.left != null) bstplus(x.left, i);
        if (x.right != null) bstplus(x.right, i);
        return x;
    }
}
```
