### 解题思路
此处撰写解题思路

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
    public static boolean isBalanced(TreeNode root) {
        	if(root==null)
			return true;
		int left=maxDepth(root.left);
		int right=maxDepth(root.right);
		int diff=left-right;
		if(diff>1 || diff<-1) {
			return false;
		}
		return isBalanced(root.left) &&isBalanced(root.right);
    }
    public static int maxDepth(TreeNode root) {
		if(root==null)
			return 0;
		int nLeft=maxDepth(root.left);
		int nRight=maxDepth(root.right);
		
		return (nLeft>nRight)?(nLeft+1):(nRight+1);
	}
}
```