```Java
class Solution{
	public int pathSum(TreeNode root,int sum){
		if(root==null)
			return 0;
		return pathSum(root.left,sum)+pathSum(root.right,sum)+FindPath(root,sum);
	}
	public  int FindPath(TreeNode root,int sum){
		if(root==null)
			return 0;
		return ((root.val==sum)?1:0)+FindPath(root.left,sum-root.val)+FindPath(root.right,sum-root.val);
	}
}
```