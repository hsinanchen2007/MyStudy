
思路：递归
1.所有的值都要和root.val相等
2.只要有一个值不等就会返回false
```
public static boolean get(TreeNode root,int k) {
		if (root == null) return true;
		
		if (k != root.val) return false;
			
		return get(root.left,k) && get(root.right,k);
	}
	
    public boolean isUnivalTree(TreeNode root) {
        if (root == null) return true;
        return get(root,root.val);
    }
```

