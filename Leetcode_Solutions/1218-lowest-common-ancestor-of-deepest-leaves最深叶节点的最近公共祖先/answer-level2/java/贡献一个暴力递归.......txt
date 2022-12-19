看了题解没有暴力递归
暴力递归有点夯余,有点慢,思想还是差不多得....
```java
class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        if (root==null) return root;
         TreeNode left=lcaDeepestLeaves(root.left);
         TreeNode right=lcaDeepestLeaves(root.right);
          int l=Helper(root.left);
         int r=Helper(root.right);
         if(l==r)return root;
         return l>r?left:right;
    }
    //如果左右子树高度一样，返回根节点
    //如果不一样，返回高的那个的叶子节点
    //这个函数返回一棵树的高度
    private int Helper(TreeNode root){
        if (root==null) return 0;
        return Math.max(Helper(root.left),Helper(root.right))+1;
    }
}
```