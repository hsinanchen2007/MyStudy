### 解题思路
迭代，
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
    public int diameterOfBinaryTree(TreeNode root) {
           if(root==null)
            	return 0;
            else {
            	int left=findlength(root.left)+1;
            	int right=findlength(root.right)+1;
            		int leftTree=diameterOfBinaryTree(root.left);
            	int rightTree=diameterOfBinaryTree(root.right);
            	 int max=leftTree>rightTree?leftTree:rightTree;
            	 max=max>(left+right-2)?max:(left+right-2);
            	 return max;
            }
	    }
	private int findlength(TreeNode root) {
		if(root==null)
			return 0;
		return Math.max(findlength(root.left), findlength(root.right))+1;
	}
}
```