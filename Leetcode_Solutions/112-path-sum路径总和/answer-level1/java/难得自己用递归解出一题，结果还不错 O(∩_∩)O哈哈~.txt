![1577367696(1).png](https://pic.leetcode-cn.com/42fb42e452eb0a8c695d66fcb40b310ca1bdb63470b3d16c2997c03b828704a9-1577367696\(1\).png)







```
public boolean hasPathSum(TreeNode root,int sum){
        
        
		if(root==null) return false;
		//确保是根结点到叶子结点 单独的根结点不算
		if(root.val==sum&&root.left==null&&root.right==null) return true;
		//到了叶子结点 仍没有返回true 就直接返回false
		if(root.left==null&&root.right==null) return false;

		//左边是否能找到正确的路径？ 
		// 每次经过一个结点就将sum减去结点的值 当叶子结点的值正好等于sum剩下的值（每一次新的sum）就说明路径存在
		boolean res1=hasPathSum(root.left,sum-root.val);

		//左边找到了直接返回true
		if(res1==true) return res1;

		//否则在右边找一遍
		boolean res2=hasPathSum(root.right,sum-root.val);

		//右边找到了就返回true 没有找到就false
	     return res2;

	}
```
