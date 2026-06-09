```
/**
 * 递归解法
 */
class Solution{
	public boolean isBalanced(TreeNode root){
		if(root==null)
			return true;
		int left=0,right=0;
		if(root.left!=null)
			left=depth(root.left);
		if(root.right!=null)
			right=depth(root.right);
		if(Math.abs(left-right)>1)
			return false;
		else return isBalanced(root.left)&&isBalanced(root.right);
	}
	public int depth(TreeNode root){
		if(root==null)
			return 0;
		int left=0,right=0;
		if(root.left!=null)
			left=depth(root.left);
		if(root.right!=null)
			right=depth(root.right);
		return Math.max(left,right)+1;
	}
}
```