```
class Solution{
	int res=0;
	public int rangeSumBST(TreeNode root,int L,int R){
		if(root.left!=null)
			rangeSumBST(root.left,L,R);
		if(root.right!=null)
			rangeSumBST(root.right,L,R);
		if(root.val>=L&&root.val<=R)
			res+=root.val;
		return res;
	}
}
```