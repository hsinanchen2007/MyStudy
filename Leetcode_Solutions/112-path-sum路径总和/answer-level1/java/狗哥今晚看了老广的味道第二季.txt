### 解题思路
递归产生疑惑美

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
   //路径总和
	public boolean hasPathSum(TreeNode root, int sum) {
		return dohasPathSum(root,sum,0);
	}

	private boolean dohasPathSum(TreeNode parent, int sum, int curSum) {
		if(parent==null)return false;
		if(parent.left==null&&parent.right==null&&curSum+parent.val==sum)return true;
		return dohasPathSum(parent.left, sum, curSum+parent.val)
				||dohasPathSum(parent.right, sum, curSum+parent.val);
	}
}
```