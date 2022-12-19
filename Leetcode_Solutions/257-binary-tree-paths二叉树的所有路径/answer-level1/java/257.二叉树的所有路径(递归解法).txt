```
class Solution{
	public List<String>binaryTreePaths(TreeNode root){
		List<String>res=new ArrayList<>();
		if(root==null)
			return res;
		String temp="";
		helper(res,temp,root);
		return res;
	}
	public void helper(List<String>res,String temp,TreeNode root){
		if(root==null)
			return;
		temp+=root.val;
		if(root.left==null&&root.right==null){
			res.add(temp);
			return;
		}else{
			helper(res,temp+"->",root.left);
			helper(res,temp+"->",root.right);
		}
	}
}
```