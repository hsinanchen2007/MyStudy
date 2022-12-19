```
boolean res = false;
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null){
            return false;
        }
        judge(root,sum,0);
        return res;
    }

    public void judge(TreeNode root, int sum, int nodeSum){
        nodeSum += root.val;
		if (root.left == null && root.right == null) {
			if (nodeSum == sum) {
				res = true;
			}
			return;
		}

		if (root.left != null) {
			judge(root.left, sum, nodeSum);
		}
		if (root.right != null) {
			judge(root.right, sum, nodeSum);
		}
    }
```
