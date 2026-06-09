```Java
class Solution{
	public int sumOfLeftLeaves(TreeNode root){
		int res=0;
		if(root==null)
			return res;
		if(root.left==null&&root.right==null)
			return res;
		if(root.left!=null&&root.left.left==null&&root.left.right==null)
			res+=root.left.val;
		else if(root.left!=null)
			res+=sumOfLeftLeaves(root.left);
		if(root.right!=null)
			res+=sumOfLeftLeaves(root.right);
		return res;
	}

}
```