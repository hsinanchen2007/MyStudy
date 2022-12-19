### 解题思路
不用数组存储
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
  public boolean isValidBST(TreeNode root) {
		if (root == null)
			return true;
		return helper(root);
  }

	TreeNode prev;

	private boolean helper(TreeNode parent) {
		if (parent == null)
			return true;
		if (!helper(parent.left)) {
			return false;
		}
		if(prev!=null&&prev.val>=parent.val) {
			return false;
		}
		prev = parent;
		return helper(parent.right);
	}
}
```