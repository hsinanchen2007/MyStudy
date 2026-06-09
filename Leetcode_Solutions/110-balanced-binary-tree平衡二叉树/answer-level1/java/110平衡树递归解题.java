这个题和104求树的最大高度类似，用递归求出左右子树的最大高度，

然后相减的结果小于1就是true。


先设置result=true这个外部变量，如果相减的结果差大于1就让result为false。（ps：java不好可能表达不够好，思想就是这样）
```
public boolean result= true;
 public boolean isBalanced(TreeNode root){
       helper(root);
       return result;
 }
  private int helper (TreeNode root){
      if(root ==null)return 0;
      int l = helper(root.left);
      int r = helper(root.right);
      if(Math.abs(l-r)>1) result=false;
      return (Math.max(l,r)+1);
      
  }
```